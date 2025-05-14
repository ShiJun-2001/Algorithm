#pragma once

#include "Graph.hpp"   // no trailing semicolon
#include <vector>
#include <queue>
#include <iostream>
#include <stack>
#include <list>
#include <set>


class Solution {
public:
    // Build a graph from an adjacency matrix
    static inline Graph createGraph(const std::vector<std::vector<int>>& mat) {
        Graph graph = Graph();
        for (auto& e : mat) {
            int u = e[0], v = e[1], w = e[2];
            // 如果不存在就 emplace 一个默认构造的 Node
            graph.nodes.try_emplace(u, Node{ u });
            graph.nodes.try_emplace(v, Node{ v });

            // 取出对原图中节点的引用
            Node& from = graph.nodes.at(u);
            Node& to = graph.nodes.at(v);

            from.nexts.push_back(&to);
            ++from.out; ++to.in;

            Edge edge(w, &from, &to);
            from.edges.push_back(edge);
            to.edges.push_back(edge);
        }

    }

};

static void bfs(const Graph& graph, int startValue) {
    // 1) 确保起点存在
    auto it = graph.nodes.find(startValue);
    if (it == graph.nodes.end()) return;

    // 2) 队列里存 Node*
    std::queue<const Node*> q;
    std::unordered_set<int> visited;

    q.push(&it->second);
    visited.insert(startValue);

    while (!q.empty()) {
        const Node* cur = q.front(); q.pop();
        std::cout << cur->value << "\n";

        // 3) 访问所有邻居（同样是指针）
        for (auto* nbr : cur->nexts) {
            if (visited.insert(nbr->value).second) {
                q.push(nbr);
            }
        }
    }
}

static void dfs(const Graph& graph, int StartValue) {
    auto it = graph.nodes.find(StartValue);
    if (it == graph.nodes.end()) return;

    std::stack<const Node*> stk;
    std::unordered_set<int> visited;

    stk.push(&it->second);
    visited.insert(StartValue);
    std::cout << StartValue << "\n";

    while (!stk.empty()) {
        const Node* cur = stk.top(); stk.pop();
        for (auto* nbr : cur->nexts) {
            if (visited.insert(nbr->value).second) {
                stk.push(cur);
                stk.push(nbr);
                std::cout << nbr->value << "\n";
                break;
            }
        }
    }
}

class TopologySort {
public:
    static std::vector<const Node*> solution(const Graph& graph) {
        std::unordered_map<const Node*, int> inMap = {};
        std::queue<const Node*> zeroInQueue = {};
        for (auto const& node : graph.nodes) {
            const Node& nodeObj = node.second;
            const Node* n = &nodeObj;
            inMap[n] = n->in;
            if (n->in == 0) zeroInQueue.push(n);
        }
        std::vector<const Node*> result = {};
        while (!zeroInQueue.empty()) {
            const Node* curr = zeroInQueue.front(); zeroInQueue.pop();
            result.push_back(curr);
            for (const Node* next : curr->nexts) {
                inMap[next] = next->in - 1;
                if (!inMap[next]) {
                    zeroInQueue.push(next);
                }
            }
        }
        return result;
    }
};
class Kruskal {
    class MySets {
    public:
        std::unordered_map <const Node*, std::list<Node*>> temp = {};
        MySets(std::list<Node*> nodes) {
            for (Node* node : nodes) {
                std::list<Node*> set = {};
                set.push_back(node);
                temp.emplace(node, set);
            }
            
        }
        bool isSameSet(Node* from, Node* to) {
            auto& set1 = temp[from];
            auto& set2 = temp[to];
            return set1 == set2;
        }
        void unionSet(Node* from, Node* to) {
            std::list<Node*> set1 = temp[from];
            std::list<Node*> set2 = temp[to];
            for (Node* n : set2) {
                set1.push_back(n);
                temp[n] = set1;   // 这样才是“更新”已有 key
            }
        }
    };
};
struct MinHeapCompare {
    bool operator()(Edge const& a, Edge const& b) const {
        return a.weight > b.weight;  // weight 小的优先级高（排在 top）
    }
};

class Prim {
public:
    static std::unordered_set<Edge> primMST(Graph& graph){
        std::priority_queue<Edge, std::vector<const Edge>, MinHeapCompare> pq(MinHeapCompare{});
        std::unordered_set<Node*> set = {};
        std::unordered_set<Edge> result = {};
       
        for (auto & node : graph.nodes) {
            
            Node& nodeObj = node.second;
            Node* n = &nodeObj;
            
            if (set.find(n) == set.end()) {
                set.insert(n);
                for (Edge edge : n->edges) {
                    pq.push(edge);
                }
               
                while (!pq.empty()) {
                    Edge cur = pq.top(); pq.pop();
                    Node* toNode = cur.to;
                   
                    if (set.find(toNode) == set.end()) {
                        set.insert(toNode);
                        result.insert(cur);
                        for (Edge nextEdge : toNode->edges) {
                            pq.push(nextEdge);
                        }
                    }
                }
            }
        }
    }
};
 
//不能有累加和为负数的环
class Dijkstra {
public:

};
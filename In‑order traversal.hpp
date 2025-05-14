#ifndef In-order_traversal_hpp
#define In-order_traversal_hpp
#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <algorithm>
struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int x) : val(x), left(nullptr), right(nullptr) {}
};
class solution {
public:
    static void inorder_iterative(Node* root)
    {
        std::stack<Node*> s;
        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                root = root->left;
            }
            else {
                root = s.top(); s.pop();
                std::cout << root->val << ' ';
                root = root->right;
            }
        }
    }
};
struct Node {
    int   val;
    Node* left = nullptr;
    Node* right = nullptr;
    explicit Node(int v) : val(v) {}
};

class Solution2 {
public:
    static void LevelOrderVerbose(Node* root) {
        if (!root) return;

        std::queue<std::pair<Node*, int>> q;
        std::unordered_map<int, int> levelCnt;

        q.emplace(root, 0);
        ++levelCnt[0];

        while (!q.empty()) {
            std::pair<Node*, int> p = q.front();
            q.pop();

            Node* curr = p.first;
            int lv = p.second;

            std::cout << "Node " << curr->val
                << "  at level " << lv
                << "  (level count = " << levelCnt[lv] << ")\n";

            if (curr->left) {
                q.emplace(curr->left, lv + 1);
                ++levelCnt[lv + 1];
            }
            if (curr->right) {
                q.emplace(curr->right, lv + 1);
                ++levelCnt[lv + 1];
            }
        }
    }
};

class ReturnType {
public:
    bool is_search;
    int max;
    int min;
    ReturnType(bool is_search, int max, int min) {
        this->is_search = is_search;
        this->max = max;
        this->min = min;
    }
};
class Solution3 {
public:
    static ReturnType* progress(Node* root) {
        if (!root) {
            return nullptr;
        }
        ReturnType* left = progress(root->left);
        ReturnType* right = progress(root->right);

        bool isBST = true;
        int min = root->val;
        int max = root->val;
        if (!left) {
            min = std::min(min, left->min);
            max = std::max(max, left->max);
        }
        if (!right) {
            min = std::min(min, right->min);
            max = std::max(max, right->max);
        }
        if (left != nullptr && (!left->is_search || left->max >= root->val)) {
            isBST = false;
        }
        if (right != nullptr && (!right->is_search || right->min <= root->val)) {
            isBST = false;
        }
        ReturnType ans = ReturnType(isBST, max, min);
        ReturnType* res = &ans;
        return res;
    }
};

class ReturnType1 {
public:
    int height;
    int nodes;

    ReturnType1(int h, int n) {
        height = h;
        nodes = n;
    }
};

class Solution4 {
public:
    static bool isF(Node* root) {
        if (!root) {
            return true;
        }
        ReturnType1 res = process(root);
        return res.nodes == (1 << res.height - 1);
    }
    static ReturnType1 process(Node* root) {
        if (!root) {
            return ReturnType1(0, 0);
        }
        ReturnType1 left = process(root->left);
        ReturnType1 right = process(root->right);

        int height = std::max(left.height, right.height) + 1;
        int nodes = left.nodes + right.nodes + 1;
    }
};




#endif // In-order_traversal_hpp
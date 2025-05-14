#pragma once


#include <unordered_map>
#include <unordered_set>
#include "Node.hpp"
#include "Edge.hpp"



class Graph {
public:
	std::unordered_map <int, Node> nodes;
	std::unordered_set <Edge> edges;

	Graph() {
		nodes = {};
		edges = {};
	}

};


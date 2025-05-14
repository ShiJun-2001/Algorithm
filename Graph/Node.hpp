#pragma once

#include <vector>
#include "Edge.hpp"

class Node {
public:
	int value;
	int in;
	int out;
	std::vector<Node*> nexts;
	std::vector<Edge> edges;
	

	Node() {
		value = 0;
		in = 0;
		out = 0;
		nexts = {};
		edges = {};
	}
	Node(int value) {
		this->value = value;
		in = 0;
		out = 0;
		nexts = {};
		edges = {};
	}
};




#pragma once

#include "Node.hpp"




class Edge {
public:
	int weight;
	Node* from;
	Node* to;

	Edge(const int weight, Node* fromNode, Node* toNode) {
		this->weight = weight;
		from = fromNode;
		to = toNode;
	}

};


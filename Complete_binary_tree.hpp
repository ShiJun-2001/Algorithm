#pragma once
#ifndef Complete_binary_tree_hpp
#define Complete_binary_tree_hpp

#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class solution {
public:
	static bool is_Complete_binary_tree(Node* root) {
		if (!root) {
			return true;
		}
		queue<Node*> res = {};
		bool leaf = false;
		Node* l = nullptr, * r = nullptr;
		res.push(root);
		while (!res.empty()) {
			root = res.front();
			res.pop();
			l = root->left;
			r = root->right;
			if ((leaf && (l != nullptr || r != nullptr)) || (l == nullptr || r != nullptr)) {
				return false;
			}
			if (l) {
				res.push(l);
			}
			if (r) {
				res.push(r);
			}
			if (l == nullptr || r == nullptr) {
				leaf = true;
			}
		}
		return true;
	}



};


#endif // Complete_binary_tree_hpp
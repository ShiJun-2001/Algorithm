#pragma once
#ifndef ISBALANCED_HPP
#define ISBALANCED_HPP

#include<iostream> 
#include<cmath>
#include<algorithm>

struct Node {
	Node* left;
	Node* right;
	int value;
	Node(int x) : value(x), left(nullptr), right(nullptr) {};
};
class ReturnType {
public:
	bool IsBalanced;
	int height;
	ReturnType(bool isBal, int hei) {
		IsBalanced = isBal;
		height = hei;
	}
};
class Solution {
	static bool isBalanced(Node* root) {
		return progress(root).IsBalanced;
	}
	static ReturnType progress(Node* root) {
		if (!root) {
			return;
		}
		ReturnType left = progress(root->left);
		ReturnType right = progress(root->right);

		int height = std::max(left.height, right.height) + 1;
		bool IsBalanced = left.IsBalanced && right.IsBalanced && (abs(left.height - right.height) < 2);
		return ReturnType(IsBalanced, height);
	}
};



#endif //ISBALANCED_HPP
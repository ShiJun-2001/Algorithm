#pragma once
#ifndef SEARCH_TREE_HPP
#define	SEARCH_TREE_HPP


struct Node {
	Node* left;
	Node* right;
	int val;
	Node(int x) : val(x), left(nullptr), right(nullptr) {};
};


class Solution {

};

#endif //SEARCH_TREE_HPP
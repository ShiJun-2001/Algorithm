#include <iostream>
#include "Leetcode.hpp"


int main() {
	std::vector<int> nums = { 4, 0, 5, -5, 3, 3, 0, - 4, -5 };
	int target = -2;
	Solution s;
	s.threeSumClosest(nums, target);
}

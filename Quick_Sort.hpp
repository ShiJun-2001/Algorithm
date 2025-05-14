#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>


class Quick_Sort {
public:
	static int calculate(std::vector<int>& p) {
		if (p.empty()) return 0;
		Q_sort(p, 0, p.size() - 1);
		return 0;
	}
private:
	static void Q_sort(std::vector<int>& p, int l, int r) {
		if (l >= r) return;
		std::swap(p[l + std::rand() % (r - l + 1)], p[r]);
		int* arr = partition(p, l, r);
		Q_sort(p, l, arr[0] - 1);
		Q_sort(p, arr[1] + 1, r); 
		delete[] arr;
	}
	static int* partition(std::vector<int>& p, int l, int r) {
		int less = l - 1;
		int more = r;

		while (l < more) {
			if (p[l] < p[r]) {
				std::swap(p[++less], p[l++]);

			}
			else if (p[l] > p[r]) {
				std::swap(p[--more], p[l]);
			}
			else {
				l++;
			}
		};
		std::swap(p[more], p[r]);
		int* temp = new int[2];
		temp[0] = less + 1;
		temp[1] = more;
		return temp;
	}
};

#endif // QUICK_SORT_HPP
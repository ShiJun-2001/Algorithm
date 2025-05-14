#ifndef MERG_SORT_HPP
#define MERG_SORT_HPP

#include <vector>
#include <iostream>
#include <algorithm>
class SmallSum {
public:
	static int calculate(std::vector<int>& arr) {
		if (arr.empty()) return 0;
		return process(arr, 0, arr.size() - 1);
	}
private:
	static int process(std::vector<int>& arr, int L, int R) {
		if (L == R) return 0;

		int mid = L + ((R - L) >> 1);
		return process(arr, L, mid)
			 + process(arr, mid + 1, R)
		     + merge(arr, L, mid, R);
	}

	static int merge(std::vector<int>& arr, int L, int M, int R) {
		std::vector<int> help(R - L + 1);
		int i = 0;
		int p1 = L;
		int p2 = M + 1;
		int res = 0;

		while (p1 <= M && p2 <= R) {
			res += arr[p1] < arr[p2] ? (R - p2 + 1) * arr[p1] : 0;
			help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
		}
		while (p1 <= M) {
			help[i++] = arr[p1++];
		}
		
		while (p2 <= R) {
			help[i++] = arr[p2++];

		}
		
		for (int j = 0; j < help.size(); j++) {
			arr[L + j] = help[j];
		}
		return res;
	}
};




#endif // MERG_SORT_HPP

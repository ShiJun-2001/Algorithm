#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

#include <vector>
#include <iostream>
#include <algorithm>

class Heap_Sort {
public:
	static void heapSort(std::vector<int>& arr) {
		if (arr.empty()) return;
		for (int i = 0; i < arr.size(); i++) {
			heapInsert(arr, i);
		}
		int heapSize = arr.size();
		std::swap(arr[0], arr[--heapSize]);
		while (heapSize > 0) {
			heapify(arr, 0, heapSize);
			std::swap(arr[0],arr[--heapSize]);
		}
	 }
private:
	static void heapInsert(std::vector<int>& arr, int index) {
		while (arr[index] > arr[(index - 1) / 2]) {
			std::swap(arr[index], arr[(index - 1) / 2]);
			index = (index - 1) / 2;
		}
	}
	static void heapify(std::vector<int>& arr, int index, int heapSize) {
		int left = index * 2 + 1;
		while (left < heapSize) {
			int largest = left + 1 < heapSize && arr[left + 1] > arr[left] ? left + 1 : left;
			largest = arr[largest] > arr[index] ? largest : index;
			if (largest == index) {
				break;
			}
			std::swap(arr[largest], arr[index]);
			index = largest;
			left = index * 2 + 1;
		}
	}
};


#endif
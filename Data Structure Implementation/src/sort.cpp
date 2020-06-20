#include "../include/sort.h"

template <typename T>
void sort::buildMinHeap(T* arr, int par, int beg, int end) {
	if (par * 2 + 1 <= end) {
		int min = (arr[par * 2] < arr[par * 2 + 1]) ? (par * 2) : (par * 2 + 1);
		if (arr[par] > arr[min]) {
			swap(arr[par], arr[min]);
			buildMinHeap(arr, min, beg, end);
		}
		return;
	}
	if (par * 2 <= end)
		if (arr[par] > arr[par * 2])
			swap(arr[par], arr[par * 2]);
}

template <typename T>
T* sort::bubbleSort(T* arr, int beg, int end) {
	for (int i = beg; i <= end; ++i)
		for (int j = beg; j <= end-i-1; ++j)
			if(arr[j] > arr[j+1])
				swap(arr[j], arr[j + 1]);
	return arr;
}

template <typename T>
T* sort::selectionSort(T* arr, int beg, int end) {
	for (int i = beg; i <= end; ++i)
		for (int j = i + 1; j <= end; ++j)
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
	return arr;
}

template <typename T>
T* sort::insertionSort(T* arr, int beg, int end) {
	for (int i = beg+1; i <= end; ++i) {
		int blank = i, var = arr[i];
		while (blank>beg && arr[blank-1] > var) {
			arr[blank] = arr[blank - 1];
			blank--;
		}
		arr[blank] = var;
	}
	return arr;
}

template <typename T>
T* sort::quickSort(T* arr, int beg, int end) {
	if (beg >= end) return arr;
	int i = beg, j = end;
	while(i != j) {
		if (i < j) {
			if(arr[i] > arr[j]) {
				swap(arr[i], arr[j]);
				swap(i, j);
				j++;
			} else j--;
		} else if (i > j) {
			if(arr[i] < arr[j]) {
				swap(arr[i], arr[j]);
				swap(i, j);
				j--;
			} else j++;
		}
	}
	quickSort(arr, beg, i - 1);
	quickSort(arr, i + 1, end);
	return arr;
}

template <typename T>
int* sort::countSort(int* arr, int beg, int end) {
	std::map <int, int> mpp;
	for (int i = beg; i <= end; ++i) {
		mpp[arr[i]]++;
	}
	int k = beg;
	for(auto it = mpp.begin(); it!= mpp.end(); ++it) {
		for (int i = 0; i < it->second; ++i) {
			arr[k++] = it->first;
		}
	}
	return arr;
}

template <typename T>
int* sort::iterativeQuickSort(T* arr, int beg, int end) {
	std::stack<pair<int, int> > range;
	range.push({beg, end});
	while (!range.empty()) {
		int rangebeg = range.top().first;
		int rangeend = range.top().second;
		range.pop();
		int i = rangebeg, j = rangeend;
		while (i != j) {
			if (i < j) {
				if (arr[i] > arr[j]) {
					swap(arr[i], arr[j]);
					swap(i, j);
					j++;
				} else j--;
			} else if (i > j) {
				if (arr[i] < arr[j]) {
					swap(arr[i], arr[j]);
					swap(i, j);
					j--;
				} else j++;
			}
		}
		if (i - 1 > rangebeg) {
			range.push({rangebeg, i - 1});
		}
		if (j + 1 < rangeend) {
			range.push({j + 1, rangeend});
		}
	}
	return arr;
}

template <typename T>
int* sort::heapSort(T* arr, int beg, int end) {
	int i = (end - beg + 1) / 2;
	for (; i >= 1; --i) {
		buildMinHeap(arr, i, beg, end);
	}
	return arr;
}
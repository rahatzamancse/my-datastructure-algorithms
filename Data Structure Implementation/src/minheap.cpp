#include "../include/minheap.h"
// Parent(i) -> (i-1)/2
// Left(i) -> i*2 + 1
// Right(i) -> i*2 + 2

template <class T>
void minHeapify(vector<T> &arr, int i) { // O(logn)
	int l = 2*i + 1;
	int r = 2*i + 2;
	int smallest = i;
	if (l < arr.size() && arr[l] < arr[i])
		smallest = l;
	if (r < arr.size() && arr[r] < arr[smallest])
		smallest = r;
	if (smallest != i) {
		swap(arr[i], arr[smallest]);
		minHeapify(smallest);
	}
}

template <class T>
void insertKey(vector<T> &arr, T k) { // O(logn)
	arr.push_back(k);
	int i = arr.size()-1;
	while(i != 0 && arr[(i-1)/2] > arr[i]) {
		swap(arr[i], arr[(i-1)/2]);
		i = (i-1)/2;
	}
}

template <class T>
void decreaseKey(vector<T> &arr, int i, T new_val) { // O(logn)
	arr[i] = new_val;
	while (i != 0 && arr[(i-1)/2] > arr[i]) {
		swap(arr[i], arr[(i-1)/2]);
		i = (i-1)/2;
	}
}

template <class T>
T extractMin(vector<T> &arr) { // O(logn)
	if (arr.size() == 1) {
		T res = arr[0];
		arr.pop_back();
		return res;
	}
	T root = arr[0];
	arr[0] = arr.back();
	arr.pop_back();
	minHeapify(0);
	return root;
}
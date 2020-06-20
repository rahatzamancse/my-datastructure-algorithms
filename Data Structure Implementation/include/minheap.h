#pragma once

#include <vector>

template <class T>
void minHeapify(vector<T> &arr, int i); // O(logn)

template <class T>
void insertKey(vector<T> &arr, T k); // O(logn)

template <class T>
void decreaseKey(vector<T> &arr, int i, T new_val); // O(logn)

template <class T>
T extractMin(vector<T> &arr); // O(logn)

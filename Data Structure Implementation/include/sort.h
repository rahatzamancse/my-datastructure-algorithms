#pragma once

#include <map>
#include <stack>

namespace sort {
	template <typename T>
	void buildMinHeap(T* arr, int par, int beg, int end);

	/**
	 * \brief Bubble sorting algorithm, O(n^2)
	 * \param arr The array to sort
	 * \param beg The starting point
	 * \param end The end index
	 * \return Returns the array after sorting
	 */
	template <typename T>
	T* bubbleSort(T *arr, int beg, int end);

	/**
	 * \brief Selection sorting algorithm, O(n^2)
	 * \param arr The array to sort
	 * \param beg The starting point
	 * \param end The end index
	 * \return Returns the array after sorting
	 */
	template <typename T>
	T* selectionSort(T *arr, int beg, int end);

	/**
	 * \brief Insertion sorting algorithm, O(n^2)
	 * \param arr The array to sort
	 * \param beg The starting point
	 * \param end The end index
	 * \return Returns the array after sorting
	 */
	template <typename T>
	T* insertionSort(T *arr, int beg, int end);

	/**
	 * \brief quick sorting algorithm
	 * \param arr The array to sort
	 * \param beg The starting point
	 * \param end The end index
	 * \return Returns the array after sorting
	 */
	template <typename T>
	T* quickSort(T *arr, int beg, int end);

	/**
	 * \brief Counting algorithm using map, O(n*logn)
	 * \param arr The integer array to sort
	 * \param beg The starting point
	 * \param end The end index
	 * \return Returns the array after sorting
	 */
	template <typename T>
	int* countSort(int *arr, int beg, int end);

	/**
	 * \brief Quicksort with stack, O(n*logn)
	 * \param arr The integer array to sort
	 * \param beg The starting point
	 * \param end The end index
	 * \return Returns the array after sorting
	 */
	template <typename T>
	int* iterativeQuickSort(T* arr, int beg, int end);

	/**
	 * \brief Heapsort, O(n*logn)
	 * \param arr The integer array to sort
	 * \param beg The starting point
	 * \param end The end index
	 * \return Returns the array after sorting
	 */
	template <typename T>
	int* heapSort(T* arr, int beg, int end);
}
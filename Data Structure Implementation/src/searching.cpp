#include "../include/searching.h"

template<class IteratorType, class ValueType>
IteratorType search::linearSearch(IteratorType beg, IteratorType end, ValueType key) {
	for (auto i = beg; i != end; ++i)
		if (*i == key)
			return i;
	return end;
}

template<class IteratorType, class ValueType>
IteratorType search::binarySearch(IteratorType beg, IteratorType end, ValueType key) {
	auto lo = beg, hi = end;
	while (std::distance(lo, hi) >= 0) {
		auto mid = lo + std::distance(lo, hi) / 2;
		if (*mid == key) return mid;
		if (*mid < key) lo = mid + 1;
		else hi = mid - 1;
	}
	return end;
}

template<class IteratorType, class ValueType>
IteratorType search::ternarySearch(IteratorType beg, IteratorType end, ValueType key) {
	auto lo = beg, hi = end;
	int dist = std::distance(lo, hi);
	while (std::distance(lo, hi) >= 0) {
		auto mid1 = lo + (1*dist)/3;
		auto mid2 = lo + (2*dist)/3;
		if (*mid1 == key) return mid1;
		if (*mid2 == key) return mid2;
		if (*mid2 < key) lo = mid2 + 1;
		else if (*mid1 < key) lo = mid1 + 1;
		if (*mid1 > key) hi = mid1 - 1;
		else if (*mid2 > key) hi = mid2 - 1;
	}
	return end;
}
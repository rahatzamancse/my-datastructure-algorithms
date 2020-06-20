#pragma once

namespace search {
	/**
	 * \brief O(n)
	 * \param beg The starting iterator
	 * \param end The ending iterator
	 * \param key The key to search
	 * \return The index of the key, return end if key not exist
	 */
	template<class IteratorType, class ValueType>
	IteratorType linearSearch(IteratorType beg, IteratorType end, ValueType key);

	/**
	 * \brief O(logn)
	 * \param beg The starting iterator
	 * \param end The ending iterator
	 * \param key The key to search
	 * \return The index of the key, return end if key not exist
	 */
	template<class IteratorType, class ValueType>
	IteratorType binarySearch(IteratorType beg, IteratorType end, ValueType key);

	/**
	 * \brief O(log(3-based)n)
	 * \param beg The starting iterator
	 * \param end The ending iterator
	 * \param key The key to search
	 * \return The index of the key, return end if key not exist
	 */
	template<class IteratorType, class ValueType>
	IteratorType ternarySearch(IteratorType beg, IteratorType end, ValueType key);
}
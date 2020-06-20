/// Name: Binary Search
/// Description: Simple implementation of binary search
/// Detail: This implementation can be easily changed and modified according to purpose
/// Guarantee: int binarySearch(
template <typename T>
int binarySearch(T container, int l, int r, int x) {
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (container[m] == x) return m;
    if (container[m] < x) l = m + 1;
    else r = m - 1;
  }
  return -1;
}
/// Name: Comparator
/// Description: For Sorting, Priority_Queue, Set etc.
/// Detail: Needs better implementation
/// Guarantee: struct MyComparator {
struct MyComparator {
  bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
    return ((a.first==b.first)?(a.second<=b.second):(a.first<b.first));
  }
};
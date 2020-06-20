/// Name: Disjoint set or Union
/// Description: Disjoint set union datastructure
/// Detail: Uses rank union optimization
/// Guarantee: class UnionFind {
class UnionFind {
 public:
  vector<int> parent;
  UnionFind(int n) : parent(n, -1) {}

  int size(int v) {
    v = find(v);
    return -parent[v];
  }

  int find(int v) {
    if (parent[v] < 0) return v;
    return parent[v] = find(parent[v]);
  }

  void union_set(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      if (size(a) < size(b)) {
        parent[b] -= parent[a];
        parent[a] = b;
      } else {
        parent[a] += parent[b];
        parent[b] = a;
      }
    }
  }

  void print() {
    for (int i = 0; i < parent.size(); i++) {
      cout << find(i) << " ";
    }
    cout << endl;
    for (int i = 0; i < parent.size(); i++) {
      cout << i << " ";
    }
    cout << endl << endl;
  }
};
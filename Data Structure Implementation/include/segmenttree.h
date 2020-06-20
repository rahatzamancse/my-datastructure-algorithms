#pragma once

class segTree {
	struct tree {
		int val;
		int prop;
		tree() : val(0), prop(0) {   }
	};
	struct tree *tree;
    void init(int *arr, int curj, int cur = 1, int curi = 1);

public:
	int size;
	segTree(int *arr, int size) : tree(new struct tree[3*size]), size(size) {
		init(arr, size);
	}
    int query(int a, int b, int cur = 1, int curi = 1, int curj = -1, int carry = 0);

	void update(int a, int b, int add, int cur = 1, int curi = 1, int curj = -1, int carry = 0);
};
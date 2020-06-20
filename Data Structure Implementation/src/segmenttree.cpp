#include "../include/segmenttree.h"

void segTree::init(int *arr, int curj, int cur = 1, int curi = 1) {
	if(curi == curj) {
		tree[cur].val = arr[curi];
		return;
	}
	init(arr, (curi + curj) / 2, cur * 2, curi);
	init(arr, curj, cur * 2 + 1, (curi + curj) / 2 + 1);
	tree[cur].val = tree[cur * 2].val + tree[cur * 2 + 1].val;
}

int segTree::query(int a, int b, int cur = 1, int curi = 1, int curj = -1, int carry = 0) {
	if (curj == -1) curj = size;
	if (curi > b || curj < a) {
		return 0;
	}
	if (curi >= a && curj <= b) {
		return tree[cur].val + carry * (curj - curi + 1);
	}
	int left =
		query(a, b, cur * 2, curi, (curi + curj) / 2, carry + tree[cur].prop);
	int right = query(a, b, cur * 2 + 1, (curi + curj) / 2 + 1, curj,
						carry + tree[cur].prop);
	return left + right;
}

void segTree::update(int a, int b, int add, int cur = 1, int curi = 1, int curj = -1, int carry = 0) {
	if (curj == -1) curj = size;
	if(curi > b || curj < a) {
		return;
	}
	if(curi >=a && curj <= b) {
		tree[cur].val += add*(curj - curi + 1);
		tree[cur].prop += add;
		return;
	}
	update(a, b, add, cur * 2, curi, (curi + curj) / 2, carry);
	update(a, b, add, cur * 2 + 1, (curi + curj) / 2 + 1, curj, carry);
	tree[cur].val = tree[cur * 2].val + tree[cur * 2 + 1].val + tree[cur].prop *(curj - curi + 1);
}
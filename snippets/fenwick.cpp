/// Name: Fenwick Tree (Binary Indexed Tree)
/// Description: Datastructure similar to segment tree
/// Detail: This implementation can be easily changed and modified according to purpose
/// Guarantee: class FenwickTree {
int pred(int val1, int val2) {
    return val1+val2;
}

class FenwickTree {
    public:
    vector<int> tree;
    int (*pred)(int, int);
    int initialVal;


    FenwickTree(vector<int> &arr, int (*pred)(int, int), int initVal): tree(arr.size()+1, initVal), pred(pred), initialVal(initVal) {
        for(int i = 0; i<arr.size(); i++)
            update(i, arr[i]);
    }

    int operator[](int q) {
        q++;
        int val = tree[q];
        for(q-= q&-q; q > 0; q-= q&-q)
            val = pred(val, tree[q]);
        return val;
    }

    void update(int q, int val) {
        q++;
        for (; q < tree.size(); q += q & -q)
          tree[q] = pred(tree[q], val);
    }
};
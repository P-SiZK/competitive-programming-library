#include <iostream>
#include <vector>

using namespace std;

template<class T>
struct BinaryIndexedTree {
	int n;
	vector<T> tree; // 1-indexed

	BinaryIndexedTree(int n) : n(n), tree(n + 1) {}

	void add(int i, T x) {
		while (i <= n) {
			tree[i] += x;
			i += i & -i;
		}
	}

	T sum(int i) {
		T s(0);
		while (i > 0) {
			s += tree[i];
			i -= i & -i;
		}
		return s;
	}

	T find(int l, int r) { // [l, r)
		return sum(r - 1) - sum(l - 1);
	}
};

long long inversion_number(const vector<int> &v) {
	const int n = v.size();
	BinaryIndexedTree<int> bit(n);
	long long res = 0;
	for (int i = 0; i < n; ++i) {
		res += i - bit.sum(v[i]);
		bit.add(v[i], 1);
	}
	return res;
}
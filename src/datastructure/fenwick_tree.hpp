#ifndef DATASTRUCTURE_FENWICK_TREE
#define DATASTRUCTURE_FENWICK_TREE

#include <vector>

template<class T>
class FenwickTree {
private:
	int n;
	std::vector<T> tree;

public:
	FenwickTree(int n) : n(n), tree(n) {}

	void add(int i, T x) {
		++i;
		while (i <= n) {
			tree[i - 1] += x;
			i += i & -i;
		}
	}

	T sum(int i) { // [0, i)
		T s{0};
		while (i > 0) {
			s += tree[i - 1];
			i -= i & -i;
		}
		return s;
	}

	T find(int l, int r) { // [l, r)
		return sum(r) - sum(l);
	}
};

#endif // DATASTRUCTURE_FENWICK_TREE

#ifndef DATASTRUCTURE_BINARY_INDEXED_TREE_HPP
#define DATASTRUCTURE_BINARY_INDEXED_TREE_HPP

#include <vector>

template<class T>
class BinaryIndexedTree {
private:
	int n;
	std::vector<T> tree; // 1-indexed

public:
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

#endif // DATASTRUCTURE_BINARY_INDEXED_TREE_HPP

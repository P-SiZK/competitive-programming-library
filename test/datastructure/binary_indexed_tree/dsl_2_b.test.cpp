// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B

#include "src/datastructure/binary_indexed_tree.hpp"

#include <iostream>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	BinaryIndexedTree<int> bit(n);
	while (q--) {
		int com, x, y;
		cin >> com >> x >> y;
		if (com) cout << bit.find(x, y + 1) << endl;
		else bit.add(x, y);
	}

	return 0;
}

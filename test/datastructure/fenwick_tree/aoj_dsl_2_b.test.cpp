// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B

#include "src/datastructure/fenwick_tree.hpp"

#include <iostream>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	FenwickTree<int> ft(n);
	while (q--) {
		int com, x, y;
		cin >> com >> x >> y;
		if (com) cout << ft.find(x - 1, y) << endl;
		else ft.add(x - 1, y);
	}

	return 0;
}

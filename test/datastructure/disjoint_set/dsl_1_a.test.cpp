// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A

#include "src/datastructure/disjoint_set.hpp"

#include <iostream>

int main() {
	int n, q;
	cin >> n >> q;
	DisjointSet ds(n);
	for (int i = 0; i < q; ++i) {
		int t, a, b;
		cin >> t >> a >> b;
		if (t == 0) ds.unite(a, b);
		else if (t == 1) {
			if (ds.same(a, b)) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}

	return 0;
}

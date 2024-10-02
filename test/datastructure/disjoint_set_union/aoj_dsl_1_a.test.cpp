// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A

#include "src/datastructure/disjoint_set_union.hpp"

#include <iostream>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	DisjointSetUnion dsu(n);
	while (q--) {
		int t, a, b;
		cin >> t >> a >> b;
		if (t == 0) dsu.unite(a, b);
		else if (t == 1) {
			if (dsu.same(a, b)) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}

	return 0;
}

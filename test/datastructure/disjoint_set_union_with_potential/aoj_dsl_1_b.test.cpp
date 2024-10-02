// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B

#include "src/datastructure/disjoint_set_union_with_potential.hpp"

#include <iostream>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	DisjointSetUnionWithPotential<int> dsu(n);
	while (q--) {
		int f;
		cin >> f;
		if (f == 0) {
			int x, y, z;
			cin >> x >> y >> z;
			dsu.unite(x, y, z);
		} else {
			int x, y;
			cin >> x >> y;
			if (dsu.same(x, y)) cout << dsu.difference(x, y) << endl;
			else cout << '?' << endl;
		}
	}

	return 0;
}

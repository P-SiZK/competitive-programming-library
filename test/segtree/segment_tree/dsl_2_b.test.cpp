// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B

#include "src/segtree/segment_tree.hpp"

#include <iostream>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	SegmentTree seg([](long long a, long long b) { return a + b; }, 0LL);
	seg.init(n);
	while (q--) {
		int com, x, y;
		cin >> com >> x >> y;
		--x;
		if (com) --y, cout << seg.find(x, y + 1) << endl;
		else seg.update(x, seg.at(x) + y);
	}

	return 0;
}

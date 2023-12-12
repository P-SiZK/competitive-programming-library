// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A

#include "src/datastructure/segment_tree.hpp"

#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	SegmentTree seg([](int a, int b) { return min(a, b); }, numeric_limits<int>::max());
	seg.init(n);
	while (q--) {
		int com, x, y;
		cin >> com >> x >> y;
		if (com) cout << seg.find(x, y + 1) << endl;
		else seg.update(x, y);
	}

	return 0;
}

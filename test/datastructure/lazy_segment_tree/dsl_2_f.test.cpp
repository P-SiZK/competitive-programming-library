// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F

#include "src/datastructure/lazy_segment_tree.hpp"

#include <iostream>
#include <limits>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	auto f = [](int a, int b) { return min(a, b); };
	auto g = []([[maybe_unused]] int a, int b) { return b; };
	LazySegmentTree seg(f, g, g, numeric_limits<int>::max(), -1);
	seg.init(n);
	while (q--) {
		int com, s, t, x;
		cin >> com >> s >> t;
		if (com) cout << seg.find(s, t + 1) << endl;
		else cin >> x, seg.update(s, t + 1, x);
	}

	return 0;
}

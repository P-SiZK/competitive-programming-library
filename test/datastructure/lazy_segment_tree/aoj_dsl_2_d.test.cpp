// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D

#include "src/datastructure/lazy_segment_tree.hpp"

#include <iostream>
#include <limits>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	auto f = [](int, int) { return 0; };
	auto g = [](int, int b) { return b; };
	auto h = [](int, int b) { return b; };
	LazySegmentTree seg(f, g, h, numeric_limits<int>::max(), -1);
	seg.init(n);
	while (q--) {
		int com;
		cin >> com;
		if (com) {
			int i;
			cin >> i;
			cout << seg.at(i) << endl;
		} else {
			int s, t, x;
			cin >> s >> t >> x;
			seg.update(s, t + 1, x);
		}
	}

	return 0;
}

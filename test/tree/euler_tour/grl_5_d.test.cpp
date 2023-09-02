// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D

#include "src/datastructure/segment_tree.hpp"
#include "src/tree/euler_tour.hpp"

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	EulerTour et(n);
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int c;
			cin >> c;
			p[c] = i;
			et.add_edge(i, c);
		}
	}
	et.build();
	SegmentTree st([](int a, int b) { return a + b; }, 0);
	st.init(2 * n);

	int q;
	cin >> q;
	while (q--) {
		int c;
		cin >> c;
		if (c == 0) {
			int v, w;
			cin >> v >> w;
			auto update = [&](int i, int x) { st.update(i, st.at(i) + x); };
			et.update_edge(v, p[v], w, update);
		} else {
			int u;
			cin >> u;
			int res = 0;
			auto query = [&](int l, int r) { res += st.find(l, r); };
			et.query_edge(u, 0, query);
			cout << res << endl;
		}
	}

	return 0;
}

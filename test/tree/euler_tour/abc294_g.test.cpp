// verification-helper: PROBLEM https://atcoder.jp/contests/abc294/tasks/abc294_g

#include "src/segtree/segment_tree.cpp"
#include "src/tree/euler_tour.cpp"

#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<tuple<int, int, long long>> uvw(n - 1);
	EulerTour et(n);
	for (int i = 0; i < n - 1; ++i) {
		auto &[u, v, w] = uvw[i];
		cin >> u >> v >> w;
		--u, --v;
		et.add_edge(u, v);
	}
	et.build();
	SegmentTree st([](long long a, long long b) { return a + b; }, 0LL);
	vector<long long> weight(2 * n);
	for (int i = 1; i < n; ++i) {
		auto [u, v, w] = uvw[i - 1];
		auto [down, up] = et.index(et.child(u, v));
		weight[down] = w;
		weight[up] = -w;
	}
	st.build(weight);

	int q;
	cin >> q;
	while (q--) {
		int c;
		cin >> c;
		if (c == 1) {
			int i;
			long long w;
			cin >> i >> w;
			auto [u, v, _] = uvw[i - 1];
			auto update = [&](int i, long long x) { st.update(i, x); };
			et.update_edge(u, v, w, update);
		} else {
			int u, v;
			cin >> u >> v;
			long long res = 0;
			auto query = [&](int l, int r) { res += st.find(l, r); };
			et.query_edge(u - 1, v - 1, query);
			cout << res << endl;
		}
	}

	return 0;
}

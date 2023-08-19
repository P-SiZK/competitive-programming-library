// verification-helper: PROBLEM https://judge.yosupo.jp/problem/vertex_add_path_sum

#include "src/segtree/segment_tree.cpp"
#include "src/tree/euler_tour.cpp"

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int &e : a) cin >> e;
	EulerTour et(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		et.add_edge(u, v);
	}
	et.build();
	SegmentTree st([](long long a, long long b) { return a + b; }, 0LL);
	vector<long long> weight(2 * n);
	for (int v = 0; v < n; ++v) {
		long long w = a[v];
		auto [down, up] = et.index(v);
		weight[down] = w;
		weight[up] = -w;
	}
	st.build(weight);

	while (q--) {
		int c;
		cin >> c;
		if (c == 0) {
			int p;
			long long x;
			cin >> p >> x;
			auto update = [&](int i, int val) { st.update(i, st.at(i) + val); };
			et.update_vertex(p, x, update);
		} else {
			int u, v;
			cin >> u >> v;
			long long res = 0;
			auto query = [&](int l, int r) { res += st.find(l, r); };
			et.query_vertex(u, v, query);
			cout << res << endl;
		}
	}

	return 0;
}

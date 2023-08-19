// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C

#include "src/tree/euler_tour.cpp"

#include <iostream>

int main() {
	int n;
	cin >> n;
	EulerTour et(n);
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int c;
			cin >> c;
			et.add_edge(i, c);
		}
	}
	et.build();

	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << et.lca(u, v) << endl;
	}

	return 0;
}

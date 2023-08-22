// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A

#include "src/graph/dijkstra.hpp"

#include <iostream>
#include <vector>

int main() {
	int v, e, r;
	cin >> v >> e >> r;
	vector<vector<pair<int, int>>> g(v);
	for (int i = 0; i < e; ++i) {
		int s, t, d;
		cin >> s >> t >> d;
		g[s].emplace_back(t, d);
	}
	vector<int> ans = dijkstra(r, g);
	for (int i = 0; i < v; ++i) {
		if (ans[i] == numeric_limits<int>::max()) cout << "INF" << endl;
		else cout << ans[i] << endl;
	}

	return 0;
}

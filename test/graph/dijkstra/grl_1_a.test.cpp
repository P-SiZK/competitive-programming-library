// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A

#include "src/graph/dijkstra.cpp"

#include <iostream>
#include <vector>

int main() {
	int V, E, r;
	cin >> V >> E >> r;
	vector<vector<pair<int, int>>> G(V);
	for (int i = 0; i < E; ++i) {
		int s, t, d;
		cin >> s >> t >> d;
		G[s].emplace_back(t, d);
	}
	vector<int> ans = dijkstra(r, G);
	for (int i = 0; i < V; ++i) {
		if (ans[i] == numeric_limits<int>::max()) cout << "INF" << endl;
		else cout << ans[i] << endl;
	}

	return 0;
}

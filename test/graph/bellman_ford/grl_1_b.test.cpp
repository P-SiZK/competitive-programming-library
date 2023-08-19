// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B

#include "src/graph/bellman_ford.cpp"

#include <iostream>
#include <vector>

int main() {
	int V, E, r;
	cin >> V >> E >> r;
	vector<Edge<int>> G;
	for (int i = 0; i < E; ++i) {
		int s, t, d;
		cin >> s >> t >> d;
		G.emplace_back(s, t, d);
	}
	vector<int> ans = bellman_ford(r, V, G);
	if (ans.empty()) cout << "NEGATIVE CYCLE" << endl;
	else {
		for (int i = 0; i < V; ++i) {
			if (ans[i] == numeric_limits<int>::max()) cout << "INF" << endl;
			else cout << ans[i] << endl;
		}
	}

	return 0;
}

/*
	created: 2019-08-27
	https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
*/

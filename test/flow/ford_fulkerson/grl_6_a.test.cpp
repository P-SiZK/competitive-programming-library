// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A

#include "src/flow/ford_fulkerson.cpp"

#include <iostream>

int main() {
	int V, E;
	cin >> V >> E;
	FordFulkerson<int> G(V);
	for (int i = 0; i < E; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		G.add_edge(u, v, c);
	}
	cout << G.max_flow(0, V - 1) << endl;

	return 0;
}

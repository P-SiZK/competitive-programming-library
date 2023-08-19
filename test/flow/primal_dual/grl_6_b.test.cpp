// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B

#include "src/flow/primal_dual.cpp"

#include <iostream>

int main() {
	int V, E, F;
	cin >> V >> E >> F;
	PrimalDual<int, int> G(V);
	for (int i = 0; i < E; ++i) {
		int u, v, c, d;
		cin >> u >> v >> c >> d;
		G.add_edge(u, v, c, d);
	}
	cout << G.min_cost_flow(0, V - 1, F) << endl;

	return 0;
}

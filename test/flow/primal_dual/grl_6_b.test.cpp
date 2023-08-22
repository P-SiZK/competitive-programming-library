// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B

#include "src/flow/primal_dual.hpp"

#include <iostream>

int main() {
	int v_sz, e_sz, flow;
	cin >> v_sz >> e_sz >> flow;
	PrimalDual<int, int> g(v_sz);
	for (int i = 0; i < e_sz; ++i) {
		int u, v, c, d;
		cin >> u >> v >> c >> d;
		g.add_edge(u, v, c, d);
	}
	cout << g.min_cost_flow(0, v_sz - 1, flow) << endl;

	return 0;
}

// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C

#include "src/graph/strongly_connected_components.hpp"

#include <iostream>

using namespace std;

int main() {
	int v, e;
	cin >> v >> e;
	StronglyConnectedComponents scc(v);
	for (int i = 0; i < e; ++i) {
		int s, t;
		cin >> s >> t;
		scc.add_edge(s, t);
	}

	scc.build();

	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << (scc.component_id(u) == scc.component_id(v) ? 1 : 0) << endl;
	}

	return 0;
}

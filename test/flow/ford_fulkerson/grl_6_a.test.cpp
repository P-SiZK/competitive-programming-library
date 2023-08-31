// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A

#include "src/flow/ford_fulkerson.hpp"

#include <iostream>

using namespace std;

int main() {
	int v_sz, e_sz;
	cin >> v_sz >> e_sz;
	FordFulkerson<int> g(v_sz);
	for (int i = 0; i < e_sz; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		g.add_edge(u, v, c);
	}
	cout << g.max_flow(0, v_sz - 1) << endl;

	return 0;
}

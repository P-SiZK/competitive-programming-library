// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A

#include "src/graph/dijkstra.hpp"

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int v, e, r;
	cin >> v >> e >> r;
	Dijkstra<int> dj(v);
	for (int i = 0; i < e; ++i) {
		int s, t, d;
		cin >> s >> t >> d;
		dj.add_edge(s, t, d);
	}
	dj.build(r);
	for (int i = 0; i < v; ++i) {
		if (dj.is_unreachable(i)) cout << "INF" << endl;
		else cout << dj.distance(i) << endl;
	}

	return 0;
}

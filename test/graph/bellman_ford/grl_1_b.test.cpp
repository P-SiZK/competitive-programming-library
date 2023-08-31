// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B

#include "src/graph/bellman_ford.hpp"

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int v, e, r;
	cin >> v >> e >> r;
	BellmanFord<int> bf(v);
	for (int i = 0; i < e; ++i) {
		int s, t, d;
		cin >> s >> t >> d;
		bf.add_edge(s, t, d);
	}
	bf.build(r);
	if (bf.has_negative_cycle()) cout << "NEGATIVE CYCLE" << endl;
	else {
		for (int i = 0; i < v; ++i) {
			if (bf.is_unreachable(i)) cout << "INF" << endl;
			else cout << bf.distance(i) << endl;
		}
	}

	return 0;
}

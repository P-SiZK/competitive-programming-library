// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A

#include "src/graph/prim.hpp"

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int v, e;
	cin >> v >> e;
	vector<vector<pair<int, int>>> g(v);
	for (int i = 0; i < e; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	cout << prim(g) << endl;

	return 0;
}

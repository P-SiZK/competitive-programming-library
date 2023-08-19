// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A

#include "src/graph/prim.cpp"

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int V, E;
	cin >> V >> E;
	vector<vector<pair<int, int>>> G(V);
	for (int i = 0; i < E; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		G[a].emplace_back(b, c);
		G[b].emplace_back(a, c);
	}
	cout << prim(G) << endl;

	return 0;
}

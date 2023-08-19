// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A

#include "src/graph/kruskal.cpp"

#include <iostream>

using namespace std;

int main() {
	int V, E;
	cin >> V >> E;
	vector<Edge<int>> G;
	for (int i = 0; i < E; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		G.emplace_back(a, b, c);
	}
	cout << kruskal(V, G) << endl;

	return 0;
}

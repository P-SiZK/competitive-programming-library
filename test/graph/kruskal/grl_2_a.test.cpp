// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A

#include "src/graph/kruskal.hpp"

#include <iostream>

using namespace std;

int main() {
	int v, e;
	cin >> v >> e;
	vector<Edge<int>> g;
	for (int i = 0; i < e; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		g.emplace_back(a, b, c);
	}
	cout << kruskal(v, g) << endl;

	return 0;
}

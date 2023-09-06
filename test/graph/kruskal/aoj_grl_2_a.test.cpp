// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A

#include "src/graph/kruskal.hpp"

#include <iostream>

using namespace std;

int main() {
	int v, e;
	cin >> v >> e;
	Kruskal<int> k(v);
	for (int i = 0; i < e; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		k.add_edge(a, b, c);
	}
	cout << k.mst_cost() << endl;

	return 0;
}

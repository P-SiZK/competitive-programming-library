// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A

#include "src/graph/prim.hpp"

#include <iostream>

using namespace std;

int main() {
	int v, e;
	cin >> v >> e;
	Prim<int> p(v);
	for (int i = 0; i < e; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		p.add_edge(a, b, c);
	}
	cout << p.mst_cost() << endl;

	return 0;
}

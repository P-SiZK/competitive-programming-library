// verification-helper: PROBLEM https://judge.yosupo.jp/problem/scc

#include "src/graph/strongly_connected_components.hpp"

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	StronglyConnectedComponents scc(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		scc.add_edge(a, b);
	}

	int k = scc.build();
	vector<vector<int>> groups(k);
	for (int i = 0; i < n; ++i) groups[scc.component_id(i)].push_back(i);

	cout << k << endl;
	for (auto const &group : groups) {
		cout << group.size();
		for (auto const &v : group) cout << " " << v;
		cout << endl;
	}

	return 0;
}

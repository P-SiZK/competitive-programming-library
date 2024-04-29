// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/1595

#include "src/tree/rerooting_dp.hpp"

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	auto f = [](int a, int b) { return max(a, b); };
	auto g = [](int a, int b) { return a + b; };
	RerootingDP<int, int, decltype(f), decltype(g)> dp(n, f, g, 0);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		dp.add_edge(u, v, 1);
	}

	dp.build();
	for (auto e : dp.reroot()) cout << 2 * (n - 1) - e << endl;

	return 0;
}

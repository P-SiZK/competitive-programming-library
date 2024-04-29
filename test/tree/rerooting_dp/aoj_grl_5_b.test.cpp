// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_B

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
		int s, t, w;
		cin >> s >> t >> w;
		dp.add_edge(s, t, w);
	}

	dp.build();
	for (auto e : dp.reroot()) cout << e << endl;

	return 0;
}

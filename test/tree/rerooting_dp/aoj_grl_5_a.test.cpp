// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A

#include "src/tree/rerooting_dp.hpp"

#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

int main() {
	int n;
	cin >> n;
	auto f = [](pair<int, int> a, pair<int, int> b) {
		int tmp = max(a.first, b.first);
		return pair(tmp, max({a.first + b.first - tmp, a.second, b.second}));
	};
	auto g = [](pair<int, int> a, int b) { return pair(a.first + b, 0); };
	RerootingDP<pair<int, int>, int, decltype(f), decltype(g)> dp(n, f, g, pair(0, 0));
	for (int i = 0; i < n - 1; ++i) {
		int s, t, w;
		cin >> s >> t >> w;
		dp.add_edge(s, t, w);
	}

	dp.build();
	int ans = 0;
	for (auto e : dp.reroot()) ans = max(ans, e.first + e.second);
	cout << ans << endl;

	return 0;
}

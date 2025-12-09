// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/2880

#include "src/datastructure/interval_set.hpp"

#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<tuple<int, int, int>> dab(m);
	for (auto &[d, a, b] : dab) cin >> d >> a >> b;
	sort(dab.begin(), dab.end());
	vector<tuple<int, int, int, int>> esti(q);
	for (int i = 0; i < q; ++i) {
		auto &[e, s, t, index] = esti[i];
		cin >> e >> s >> t;
		index = i;
	}
	sort(esti.begin(), esti.end());

	vector<bool> ans(q);
	IntervalSet<int> is(false);
	auto it = dab.begin();
	for (auto const &[e, s, t, i] : esti) {
		while (it != dab.end() && get<0>(*it) < e) {
			auto [_, a, b] = *it;
			is.insert(a, b);
			++it;
		}

		ans[i] = s >= t || is.covered(s, t);
	}

	for (auto const &f : ans) cout << (f ? "Yes" : "No") << endl;

	return 0;
}

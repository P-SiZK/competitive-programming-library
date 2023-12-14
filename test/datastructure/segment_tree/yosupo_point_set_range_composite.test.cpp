// verification-helper: PROBLEM https://judge.yosupo.jp/problem/point_set_range_composite

#include "src/datastructure/segment_tree.hpp"

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int const MOD = 998244353;

int main() {
	int n, q;
	cin >> n >> q;
	vector<pair<long long, long long>> ab(n);
	for (auto &[a, b] : ab) cin >> a >> b;

	auto f = [](pair<long long, long long> a, pair<long long, long long> b) {
		return pair(b.first * a.first % MOD,
					(b.first * a.second % MOD + b.second) % MOD);
	};
	SegmentTree seg(f, pair<long long, long long>{1LL, 0LL});
	seg.init(n);
	seg.build(ab);

	while (q--) {
		int com;
		cin >> com;
		if (com) {
			int l, r, x;
			cin >> l >> r >> x;
			auto [a, b] = seg.find(l, r);
			cout << (a * x % MOD + b) % MOD << endl;
		} else {
			int p, c, d;
			cin >> p >> c >> d;
			seg.update(p, {c, d});
		}
	}

	return 0;
}

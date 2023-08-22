// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_C
// verification-helper: ERROR 1e-5

#include "src/geometry/geometry.hpp"

#include <iomanip>
#include <iostream>

int main() {
	cout << fixed << setprecision(10);
	int n;
	cin >> n;
	Polygon p(n);
	for (auto &a : p) cin >> a;
	int q;
	cin >> q;
	while (q--) {
		Line l{};
		cin >> l;
		cout << area(convex_cut(p, l)) << endl;
	}

	return 0;
}

// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A

#include "src/geometry/geometry.hpp"

#include <iostream>

int main() {
	int n;
	cin >> n;
	Polygon p(n);
	for (auto &a : p) cin >> a;
	Polygon t = convex_hull(p);
	cout << t.size() << endl;
	for (auto a : t) cout << a.x << " " << a.y << endl;

	return 0;
}

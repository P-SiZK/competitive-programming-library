// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_B

#include "src/geometry/geometry.hpp"

#include <iostream>

int main() {
	int n;
	cin >> n;
	Polygon p(n);
	for (auto &a : p) cin >> a;
	cout << (is_convex(p) ? 1 : 0) << endl;

	return 0;
}

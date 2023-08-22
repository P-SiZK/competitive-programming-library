// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_H
// verification-helper: ERROR 1e-5

#include "src/geometry/geometry.hpp"

#include <iomanip>
#include <iostream>

int main() {
	cout << fixed << setprecision(10);
	int n;
	cin >> n;
	Circle c{};
	c.c = Point(0, 0);
	cin >> c.r;
	Polygon p(n);
	for (auto &a : p) cin >> a;
	cout << area(p, c) << endl;

	return 0;
}

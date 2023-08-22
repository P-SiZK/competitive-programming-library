// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_G
// verification-helper: ERROR 1e-5

#include "src/geometry/geometry.hpp"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
	cout << fixed << setprecision(10);
	Circle c1{}, c2{};
	cin >> c1.c >> c1.r >> c2.c >> c2.r;
	auto a = tangent_cc(c1, c2);
	vector<Point> ps;
	ps.reserve(a.size());
	for (auto e : a) ps.push_back(get_cross_point_cl(c1, e)[0]);
	sort(ps.begin(), ps.end());
	for (auto e : ps) cout << e.x << " " << e.y << endl;

	return 0;
}

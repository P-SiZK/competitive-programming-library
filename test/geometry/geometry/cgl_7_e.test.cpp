// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_E
// verification-helper: ERROR 1e-6

#include "src/geometry/geometry.hpp"

#include <algorithm>
#include <iomanip>
#include <iostream>

int main() {
	cout << fixed << setprecision(10);
	Circle c1{}, c2{};
	cin >> c1.c >> c1.r >> c2.c >> c2.r;
	auto a = get_cross_point_cc(c1, c2);
	sort(a.begin(), a.end());
	cout << a[0].x << " " << a[0].y << " " << a[1].x << " " << a[1].y << endl;

	return 0;
}

// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_F
// verification-helper: ERROR 1e-5

#include "src/geometry/geometry.cpp"

#include <algorithm>
#include <cstdio>
#include <iostream>

int main() {
	Point p;
	cin >> p;
	Circle c;
	cin >> c.c >> c.r;
	auto a = tangentCP(c, p);
	sort(a.begin(), a.end());
	printf("%.10f %.10f\n%.10f %.10f\n", a[0].x, a[0].y, a[1].x, a[1].y);

	return 0;
}

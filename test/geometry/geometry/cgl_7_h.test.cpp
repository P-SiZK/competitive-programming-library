// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_H

#include "src/geometry/geometry.cpp"

#include <cstdio>
#include <iostream>

int main() {
	int n;
	cin >> n;
	Circle c;
	c.c = Point(0, 0);
	cin >> c.r;
	Polygon p(n);
	for (auto &a : p) cin >> a;
	printf("%.10f\n", area(p, c));

	return 0;
}

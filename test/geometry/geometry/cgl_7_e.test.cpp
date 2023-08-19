// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_E
// verification-helper: ERROR 1e-6

#include "src/geometry/geometry.cpp"

#include <algorithm>
#include <cstdio>
#include <iostream>

int main() {
	Circle c1, c2;
	cin >> c1.c >> c1.r >> c2.c >> c2.r;
	auto a = getCrossPointCC(c1, c2);
	sort(a.begin(), a.end());
	printf("%.10f %.10f %.10f %.10f\n", a[0].x, a[0].y, a[1].x, a[1].y);

	return 0;
}

// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_D
// verification-helper: ERROR 1e-6

#include "src/geometry/geometry.cpp"

#include <algorithm>
#include <cstdio>
#include <iostream>

int main() {
	Circle c;
	cin >> c.c.x >> c.c.y >> c.r;
	int q;
	cin >> q;
	while (q--) {
		Line l;
		cin >> l;
		auto a = getCrossPointCL(c, l);
		sort(a.begin(), a.end());
		printf("%.10f %.10f %.10f %.10f\n", a[0].x, a[0].y, a[1].x, a[1].y);
	}

	return 0;
}

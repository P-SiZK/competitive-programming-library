// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_C

#include "src/geometry/geometry.cpp"

#include <cstdio>
#include <iostream>

int main() {
	int q;
	cin >> q;
	while (q--) {
		Segment s1, s2;
		cin >> s1 >> s2;
		Point a = getCrossPointSS(s1, s2);
		printf("%.10f %.10f\n", a.x, a.y);
	}

	return 0;
}

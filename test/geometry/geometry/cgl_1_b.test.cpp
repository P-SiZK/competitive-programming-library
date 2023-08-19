// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B

#include "src/geometry/geometry.cpp"

#include <cstdio>
#include <iostream>

int main() {
	Segment s;
	cin >> s;
	int q;
	cin >> q;
	while (q--) {
		Point p;
		cin >> p;
		Point a = reflect(s, p);
		printf("%.10f %.10f\n", a.x, a.y);
	}

	return 0;
}

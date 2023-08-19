// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_B
// verification-helper: ERROR 1e-6

#include "src/geometry/geometry.cpp"

#include <cstdio>
#include <iostream>

int main() {
	Point p1, p2, p3;
	cin >> p1 >> p2 >> p3;
	Circle c = getInscribedCircle(p1, p2, p3);
	printf("%.10f %.10f %.10f\n", c.c.x, c.c.y, c.r);

	return 0;
}

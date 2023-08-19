// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_I
// verification-helper: ERROR 1e-6

#include "src/geometry/geometry.cpp"

#include <cstdio>
#include <iostream>

int main() {
	Circle c1, c2;
	cin >> c1.c >> c1.r >> c2.c >> c2.r;
	printf("%.10f\n", area(c1, c2));

	return 0;
}

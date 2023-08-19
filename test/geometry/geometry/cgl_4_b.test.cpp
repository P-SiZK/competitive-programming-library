// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_B
// verification-helper: ERROR 1e-6

#include "src/geometry/geometry.cpp"

#include <cstdio>
#include <iostream>

int main() {
	int n;
	cin >> n;
	Polygon p(n);
	for (auto &a : p) cin >> a;
	printf("%.10f\n", convexDiameter(p));

	return 0;
}

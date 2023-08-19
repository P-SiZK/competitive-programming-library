// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_A

#include "src/geometry/geometry.cpp"

#include <cstdio>
#include <iostream>

int main() {
	int n;
	cin >> n;
	Polygon p(n);
	for (auto &a : p) cin >> a;
	printf("%.1f\n", area(p));

	return 0;
}

// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_C
// verification-helper: ERROR 1e-5

#include "src/geometry/geometry.cpp"

#include <cstdio>
#include <iostream>

int main() {
	int n;
	cin >> n;
	Polygon p(n);
	for (auto &a : p) cin >> a;
	int q;
	cin >> q;
	while (q--) {
		Line l;
		cin >> l;
		printf("%.10f\n", area(convexCut(p, l)));
	}

	return 0;
}

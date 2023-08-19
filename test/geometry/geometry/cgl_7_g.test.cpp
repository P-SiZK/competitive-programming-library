// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_G
// verification-helper: ERROR 1e-5

#include "src/geometry/geometry.cpp"

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int main() {
	Circle c1, c2;
	cin >> c1.c >> c1.r >> c2.c >> c2.r;
	auto a = tangentCC(c1, c2);
	vector<Point> ps;
	ps.reserve(a.size());
	for (auto e : a) ps.push_back(getCrossPointCL(c1, e)[0]);
	sort(ps.begin(), ps.end());
	for (auto e : ps) printf("%.10f %.10f\n", e.x, e.y);

	return 0;
}

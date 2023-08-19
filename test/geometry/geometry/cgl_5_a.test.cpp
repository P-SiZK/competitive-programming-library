// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/5/CGL_5_A

#include "src/geometry/geometry.cpp"

#include <cstdio>
#include <iostream>
#include <vector>

int main() {
	int n;
	cin >> n;
	vector<Point> ps(n);
	for (auto &a : ps) cin >> a;
	printf("%.10f\n", closestPair(ps));

	return 0;
}

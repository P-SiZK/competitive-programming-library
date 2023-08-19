// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_B

#include "src/geometry/geometry.cpp"

#include <iostream>

int main() {
	int n;
	cin >> n;
	Polygon p(n);
	for (auto &a : p) cin >> a;
	cout << (isConvex(p) ? 1 : 0) << endl;

	return 0;
}

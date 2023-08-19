// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A

#include "src/geometry/geometry.cpp"

#include <iostream>

int main() {
	int n;
	cin >> n;
	Polygon p(n);
	for (auto &a : p) cin >> a;
	Polygon t = convexHull(p);
	cout << t.size() << endl;
	for (auto a : t) cout << a.x << " " << a.y << endl;

	return 0;
}

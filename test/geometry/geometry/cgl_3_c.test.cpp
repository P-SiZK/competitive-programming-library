// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C

#include "src/geometry/geometry.cpp"

#include <iostream>

int main() {
	int n;
	cin >> n;
	Polygon g(n);
	for (auto &a : g) cin >> a;
	int q;
	cin >> q;
	while (q--) {
		Point p;
		cin >> p;
		cout << contains(g, p) << endl;
	}

	return 0;
}

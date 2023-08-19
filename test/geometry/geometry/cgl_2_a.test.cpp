// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A

#include "src/geometry/geometry.cpp"

#include <iostream>

int main() {
	int q;
	cin >> q;
	while (q--) {
		Vector p0, p1, p2, p3;
		cin >> p0 >> p1 >> p2 >> p3;
		if (isParallel(p1 - p0, p3 - p2)) cout << 2;
		else if (isOrthogonal(p1 - p0, p3 - p2)) cout << 1;
		else cout << 0;
		cout << endl;
	}

	return 0;
}

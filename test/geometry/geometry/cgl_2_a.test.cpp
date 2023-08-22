// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A

#include "src/geometry/geometry.hpp"

#include <iostream>

int main() {
	int q;
	cin >> q;
	while (q--) {
		Vector p0{}, p1{}, p2{}, p3{};
		cin >> p0 >> p1 >> p2 >> p3;
		if (is_parallel(p1 - p0, p3 - p2)) cout << 2;
		else if (is_orthogonal(p1 - p0, p3 - p2)) cout << 1;
		else cout << 0;
		cout << endl;
	}

	return 0;
}

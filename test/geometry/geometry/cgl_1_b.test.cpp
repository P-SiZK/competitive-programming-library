// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B
// verification-helper: ERROR 1e-8

#include "src/geometry/geometry.hpp"

#include <iomanip>
#include <iostream>

int main() {
	cout << fixed << setprecision(10);
	Segment s{};
	cin >> s;
	int q;
	cin >> q;
	while (q--) {
		Point p{};
		cin >> p;
		Point a = reflect(s, p);
		cout << a.x << " " << a.y << endl;
	}

	return 0;
}

// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_D
// verification-helper: ERROR 1e-6

#include "src/geometry/geometry.hpp"

#include <algorithm>
#include <iomanip>
#include <iostream>

int main() {
	cout << fixed << setprecision(10);
	Circle c{};
	cin >> c.c.x >> c.c.y >> c.r;
	int q;
	cin >> q;
	while (q--) {
		Line l{};
		cin >> l;
		auto a = get_cross_point_cl(c, l);
		sort(a.begin(), a.end());
		cout << a[0].x << " " << a[0].y << " " << a[1].x << " " << a[1].y
			 << endl;
	}

	return 0;
}

// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_F
// verification-helper: ERROR 1e-5

#include "src/geometry/geometry.hpp"

#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	cout << fixed << setprecision(10);
	Point p{};
	cin >> p;
	Circle c{};
	cin >> c.c >> c.r;
	auto a = tangent_cp(c, p);
	sort(a.begin(), a.end());
	cout << a[0].x << " " << a[0].y << endl << a[1].x << " " << a[1].y << endl;

	return 0;
}

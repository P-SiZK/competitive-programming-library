// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_B
// verification-helper: ERROR 1e-6

#include "src/geometry/geometry.hpp"

#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	cout << fixed << setprecision(10);
	Point p1{}, p2{}, p3{};
	cin >> p1 >> p2 >> p3;
	Circle c = get_inscribed_circle(p1, p2, p3);
	cout << c.c.x << " " << c.c.y << " " << c.r << endl;

	return 0;
}

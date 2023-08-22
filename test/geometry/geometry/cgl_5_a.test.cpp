// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/5/CGL_5_A
// verification-helper: ERROR 1e-6

#include "src/geometry/geometry.hpp"

#include <iomanip>
#include <iostream>
#include <vector>

int main() {
	cout << fixed << setprecision(10);
	int n;
	cin >> n;
	vector<Point> ps(n);
	for (auto &a : ps) cin >> a;
	cout << closest_pair(ps) << endl;

	return 0;
}

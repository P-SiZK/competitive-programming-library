// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_B
// verification-helper: ERROR 1e-6

#include "src/geometry/geometry.hpp"

#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	cout << fixed << setprecision(10);
	int n;
	cin >> n;
	Polygon p(n);
	for (auto &a : p) cin >> a;
	cout << convex_diameter(p) << endl;

	return 0;
}

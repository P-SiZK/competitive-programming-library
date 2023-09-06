// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_A

#include "src/geometry/geometry.hpp"

#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	cout << fixed << setprecision(1);
	int n;
	cin >> n;
	Polygon p(n);
	for (auto &a : p) cin >> a;
	cout << area(p) << endl;

	return 0;
}

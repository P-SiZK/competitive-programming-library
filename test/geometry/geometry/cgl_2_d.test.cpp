// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D
// verification-helper: ERROR 1e-8

#include "src/geometry/geometry.hpp"

#include <iomanip>
#include <iostream>

int main() {
	cout << fixed << setprecision(10);
	int q;
	cin >> q;
	while (q--) {
		Segment s1{}, s2{};
		cin >> s1 >> s2;
		cout << get_distance_ss(s1, s2) << endl;
	}

	return 0;
}

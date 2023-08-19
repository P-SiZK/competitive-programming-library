// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B

#include "src/geometry/geometry.cpp"

#include <iostream>

int main() {
	int q;
	cin >> q;
	while (q--) {
		Segment s1, s2;
		cin >> s1 >> s2;
		cout << (intersectSS(s1, s2) ? 1 : 0) << endl;
	}

	return 0;
}

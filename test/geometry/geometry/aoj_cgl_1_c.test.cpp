// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C

#include "src/geometry/geometry.hpp"

#include <iostream>

using namespace std;

int main() {
	Point p0{}, p1{}, p2{};
	cin >> p0 >> p1;
	int q;
	cin >> q;
	while (q--) {
		cin >> p2;
		int a = ccw(p0, p1, p2);
		if (a == COUNTER_CLOCKWISE) cout << "COUNTER_CLOCKWISE";
		else if (a == CLOCKWISE) cout << "CLOCKWISE";
		else if (a == ONLINE_BACK) cout << "ONLINE_BACK";
		else if (a == ONLINE_FRONT) cout << "ONLINE_FRONT";
		else cout << "ON_SEGMENT";
		cout << endl;
	}

	return 0;
}

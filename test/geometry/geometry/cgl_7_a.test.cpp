// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_A

#include "src/geometry/geometry.hpp"

#include <iostream>

using namespace std;

int main() {
	Circle c1{}, c2{};
	cin >> c1.c >> c1.r >> c2.c >> c2.r;
	cout << intersect_cc(c1, c2) << endl;

	return 0;
}

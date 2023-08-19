// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/6/CGL_6_A

#include "src/geometry/geometry.cpp"

#include <iostream>
#include <vector>

int main() {
	int n;
	cin >> n;
	vector<Segment> ss(n);
	for (auto &a : ss) cin >> a;
	cout << manhattanIntersection(ss) << endl;

	return 0;
}

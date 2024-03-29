// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/6/CGL_6_A

#include "src/geometry/geometry.hpp"

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<Segment> ss(n);
	for (auto &a : ss) cin >> a;
	cout << manhattan_intersection(ss) << endl;

	return 0;
}

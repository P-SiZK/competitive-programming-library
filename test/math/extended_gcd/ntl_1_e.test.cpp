// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E

#include "src/math/extended_gcd.cpp"

#include <iostream>

using namespace std;

int main() {
	int a, b, x, y;
	cin >> a >> b;
	extended_gcd(a, b, x, y);
	cout << x << " " << y << endl;

	return 0;
}

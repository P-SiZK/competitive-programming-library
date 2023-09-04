// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/3079

#include "src/math/matrix.hpp"
#include "src/math/mod_int.hpp"

#include <iostream>

using namespace std;

int main() {
	long long n;
	cin >> n;
	Matrix<ModInt<int>> a(3), b(3, 1);
	a[0][1] = a[0][2] = a[1][0] = a[2][1] = 1;
	b[0][0] = 1;
	cout << (a.pow(n) * b)[0][0] << endl;

	return 0;
}

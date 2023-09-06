// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/7/ITP1_7_D

#include "src/math/matrix.hpp"

#include <iostream>

using namespace std;

int main() {
	int n, m, l;
	cin >> n >> m >> l;
	Matrix<long long> a(n, m), b(m, l);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) cin >> a[i][j];
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < l; ++j) cin >> b[i][j];
	auto c = a * b;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < l; ++j) {
			if (j) cout << " ";
			cout << c[i][j];
		}
		cout << endl;
	}

	return 0;
}

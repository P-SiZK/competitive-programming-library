// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D

#include "src/math/sieve_of_eratosthenes.hpp"

#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int res = 0;
	for (auto d : SieveOfEratosthenes(c).divisor(c)) {
		if (a <= d && d <= b) ++res;
	}
	cout << res << endl;

	return 0;
}

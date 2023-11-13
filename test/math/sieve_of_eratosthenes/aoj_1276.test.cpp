// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/1276

#include "src/math/sieve_of_eratosthenes.hpp"

#include <iostream>

using namespace std;

int main() {
	SieveOfEratosthenes sieve(1299709);
	int n;
	while (cin >> n, n) {
		int lcnt = 0, rcnt = 0;
		while (!sieve.is_prime(n - lcnt)) ++lcnt;
		while (!sieve.is_prime(n + rcnt)) ++rcnt;
		cout << lcnt + rcnt << endl;
	}

	return 0;
}

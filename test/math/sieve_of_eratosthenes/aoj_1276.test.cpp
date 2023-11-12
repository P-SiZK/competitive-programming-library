// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/1276

#include "src/math/sieve_of_eratosthenes.hpp"

#include <iostream>

using namespace std;

int main() {
	SieveOfEratosthenes sieve(1299709);
	auto prime_table = sieve.prime_table();
	int n;
	while (cin >> n, n) {
		int lcnt = 0, rcnt = 0;
		while (!prime_table[n - lcnt]) ++lcnt;
		while (!prime_table[n + rcnt]) ++rcnt;
		cout << lcnt + rcnt << endl;
	}

	return 0;
}

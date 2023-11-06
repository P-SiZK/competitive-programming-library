// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/1626

#include "src/math/divisor.hpp"

#include <iostream>

using namespace std;

int main() {
	int b;
	while (cin >> b, b) {
		int bottom = b, num = 1;
		for (auto v : divisor(2 * b)) {
			int tmp = (2 * b / v - v + 1);
			if (tmp <= 0 || tmp & 1) continue;
			bottom = tmp / 2;
			num = v;
		}
		cout << bottom << " " << num << endl;
	}

	return 0;
}

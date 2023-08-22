// verification-helper: PROBLEM https://atcoder.jp/contests/abc145/tasks/abc145_d

#include "src/math/combination.hpp"

#include <iostream>

using namespace std;

int main() {
	Combination<long long> comb;
	int x, y;
	cin >> x >> y;
	int xx = -x + 2 * y, yy = 2 * x - y;
	x = xx / 3, y = yy / 3;
	if (xx < 0 || yy < 0 || xx % 3 != 0 || yy % 3 != 0) cout << 0 << endl;
	else cout << comb.combination(x + y, x) << endl;

	return 0;
}

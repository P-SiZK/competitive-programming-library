// verification-helper: PROBLEM https://atcoder.jp/contests/abc145/tasks/abc145_d

#include "src/math/combination.cpp"

#include <iostream>

using namespace std;

int main() {
	init_combination();
	int x, y;
	cin >> x >> y;
	int xx = -x + 2 * y, yy = 2 * x - y;
	x = xx / 3, y = yy / 3;
	if (xx < 0 || yy < 0 || xx % 3 != 0 || yy % 3 != 0) cout << 0 << endl;
	else cout << combination(x + y, x) << endl;

	return 0;
}

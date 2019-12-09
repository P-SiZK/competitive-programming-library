#include <iostream>

using namespace std;

const int MOD = 1000000007;
const int MAX = 1100000;

long long fac[MAX], finv[MAX], inv[MAX];

void comInit() {
	fac[0] = fac[1] = inv[1] = finv[0] = finv[1] = 1;
	for (int i = 2; i < MAX; ++i) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

long long nCr(int n, int r) {
	if (n < r || n < 0 || r < 0) return 0;
	return fac[n] * (finv[r] * finv[n - r] % MOD) % MOD;
}

int main() {
	comInit();
	int x, y; cin >> x >> y;
	int xx = -x + 2 * y, yy = 2 * x - y;
	x = xx / 3, y = yy / 3;
	if (xx < 0 || yy < 0 || xx % 3 != 0 || yy % 3 != 0) cout << 0 << endl;
	else cout << nCr(x + y, x) << endl;
	
	return 0;
}
/*
	created: 2019-12-09
	https://atcoder.jp/contests/abc145/tasks/abc145_d
*/

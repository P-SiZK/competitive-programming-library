const int MOD = 1000000007;
const int MAX = 1100000;

long long fac[MAX], finv[MAX], inv[MAX];

void init_combination() {
	fac[0] = fac[1] = inv[1] = finv[0] = finv[1] = 1;
	for (int i = 2; i < MAX; ++i) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

long long combination(int n, int r) {
	if (n < r || n < 0 || r < 0) return 0;
	return fac[n] * (finv[r] * finv[n - r] % MOD) % MOD;
}

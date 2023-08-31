#include <cstddef>

template<class T, std::size_t SIZE = 1100000, T MOD = 1000000007>
class Combination {
private:
	T fac[SIZE], finv[SIZE], inv[SIZE];

public:
	Combination() {
		fac[0] = fac[1] = inv[1] = finv[0] = finv[1] = 1;
		for (std::size_t i = 2; i < SIZE; ++i) {
			fac[i] = fac[i - 1] * i % MOD;
			inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
			finv[i] = finv[i - 1] * inv[i] % MOD;
		}
	}

	T factorial(int n) { return fac[n]; }

	T inverse_factorial(int n) { return finv[n]; }

	T combination(int n, int r) {
		if (n < r || n < 0 || r < 0) return 0;
		return fac[n] * (finv[r] * finv[n - r] % MOD) % MOD;
	}
};

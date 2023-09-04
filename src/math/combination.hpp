#ifndef MATH_COMBINATION_HPP
#define MATH_COMBINATION_HPP

#include <array>

template<class T, int SIZE = 1100000, T MOD = 1000000007>
class Combination {
private:
	std::array<T, SIZE> fac, finv, inv;

public:
	Combination() {
		fac[0] = fac[1] = inv[1] = finv[0] = finv[1] = 1;
		for (int i = 2; i < SIZE; ++i) {
			fac[i] = fac[i - 1] * i % MOD;
			inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
			finv[i] = finv[i - 1] * inv[i] % MOD;
		}
	}

	T inverse(int n) { return inv[n]; }

	T factorial(int n) { return fac[n]; }

	T inverse_factorial(int n) { return finv[n]; }

	T permutation(int n, int r) {
		if (n < r || n < 0 || r < 0) return 0;
		return fac(n) * finv(n - r);
	}

	T combination(int n, int r) {
		if (n < r || n < 0 || r < 0) return 0;
		return fac[n] * (finv[r] * finv[n - r] % MOD) % MOD;
	}
};

#endif // MATH_COMBINATION_HPP

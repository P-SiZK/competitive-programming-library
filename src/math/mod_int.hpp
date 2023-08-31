#ifndef MATH_MOD_INT_HPP
#define MATH_MOD_INT_HPP

#include <iostream>

template<class T, T MOD = 1000000007>
class ModInt {
private:
	T x;

public:
	ModInt() : x(0) {}

	ModInt(long long y) : x(y % MOD) {
		if (x < 0) x += MOD;
	}

	ModInt &operator+=(ModInt const &a) {
		x += a.x;
		if (x >= MOD) x -= MOD;
		return *this;
	}

	ModInt &operator-=(ModInt const &a) {
		x += MOD - a.x;
		if (x >= MOD) x -= MOD;
		return *this;
	}

	ModInt &operator*=(ModInt const &a) {
		x = 1LL * x * a.x % MOD;
		return *this;
	}

	ModInt &operator/=(ModInt const &a) {
		*this *= a.inv();
		return *this;
	}

	ModInt operator+(ModInt const &a) const { return ModInt(x) += a; }

	ModInt operator-(ModInt const &a) const { return ModInt(x) -= a; }

	ModInt operator*(ModInt const &a) const { return ModInt(x) *= a; }

	ModInt operator/(ModInt const &a) const { return ModInt(x) /= a; }

	ModInt operator-() const { return ModInt(-x); }

	bool operator==(ModInt const &a) const { return x == a.x; }

	bool operator!=(ModInt const &a) const { return x != a.x; }

	bool operator<(ModInt const &a) const { return x < a.x; }

	friend std::ostream &operator<<(std::ostream &os, ModInt const &a) {
		return os << a.x;
	}

	friend std::istream &operator>>(std::istream &is, ModInt &a) {
		T t;
		is >> t;
		a = ModInt(t);
		return is;
	}

	ModInt inv() const {
		T a = x, b = MOD, u = 1, v = 0;
		while (b > 0) {
			T t = a / b;
			a -= t * b, u -= t * v;
			std::swap(a, b);
			std::swap(u, v);
		}
		return ModInt(u);
	}

	ModInt pow(long long n) const {
		ModInt res(1), tmp(x);
		while (n > 0) {
			if (n & 1) res *= tmp;
			tmp *= tmp;
			n >>= 1;
		}
		return res;
	}

	static ModInt comb(long long n, long long k) {
		ModInt num(1), den(1);
		for (int i = 0; i < k; ++i) {
			num *= ModInt(n - i);
			den *= ModInt(i + 1);
		}
		return num / den;
	}
};

#endif // MATH_MOD_INT_HPP

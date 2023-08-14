#include <iostream>

using namespace std;

template<typename T, T MOD = 1000000007>
struct ModInt {
	T x;

	ModInt() : x(0) {}

	ModInt(long long y) {
		x = y % MOD;
		if (x < 0) x += MOD;
	}

	ModInt &operator+=(const ModInt &a) {
		if ((x += a.x) >= MOD) x -= MOD;
		return *this;
	}

	ModInt &operator-=(const ModInt &a) {
		if ((x += MOD - a.x) >= MOD) x -= MOD;
		return *this;
	}

	ModInt &operator*=(const ModInt &a) {
		x = 1LL * x * a.x % MOD;
		return *this;
	}

	ModInt &operator/=(const ModInt &a) {
		*this *= a.inv();
		return *this;
	}

	ModInt operator+(const ModInt &a) const { return ModInt(x) += a; }

	ModInt operator-(const ModInt &a) const { return ModInt(x) -= a; }

	ModInt operator*(const ModInt &a) const { return ModInt(x) *= a; }

	ModInt operator/(const ModInt &a) const { return ModInt(x) /= a; }

	ModInt operator-() const { return ModInt(-x); }

	bool operator==(const ModInt a) const { return x == a.x; }

	bool operator!=(const ModInt a) const { return x != a.x; }

	bool operator<(const ModInt a) const { return x < a.x; }

	friend ostream &operator<<(ostream &os, const ModInt &a) {
		return os << a.x;
	}

	friend istream &operator>>(istream &is, ModInt &a) {
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
			swap(a, b);
			swap(u, v);
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

int main() { return 0; }

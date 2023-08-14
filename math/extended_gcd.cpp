#include <iostream>

using namespace std;

template<class T>
T extended_gcd(T a, T b, T &x, T &y) { // ax+by=gcd(a,b)
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	T d = extended_gcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

template<class T>
T modinv(T a, T mod) { // a,modは互いに素
	T x, y;
	extended_gcd(a, mod, x, y);
	return (x % mod + mod) % mod;
}

int main() {
	int a, b, x, y;
	cin >> a >> b;
	extended_gcd(a, b, x, y);
	cout << x << " " << y << endl;

	return 0;
}

/*
	created: 2019-08-29
	https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
*/

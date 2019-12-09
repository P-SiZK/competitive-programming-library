#include <iostream>

using namespace std;

//BEGIN
template <typename T>
T extGCD(T a, T b, T& x, T& y) { //ax+by=gcd(a,b)
	if (b == 0) {
		x = 1; y = 0;
		return a;
	}
	T d = extGCD(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

template <typename T>
T modinv(T a, T mod) { //a,modは互いに素
	T x, y;
	extGCD(a, mod, x, y);
	return (x % mod + mod) % mod;
}
//END

int main() {
	int a, b, x, y; cin >> a >> b;
	extGCD(a, b, x, y);
	cout << x << " " << y << endl;
		
	return 0;
}
/*
	created: 2019-08-29
	https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
*/

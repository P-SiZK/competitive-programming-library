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

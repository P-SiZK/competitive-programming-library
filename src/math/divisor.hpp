#ifndef MATH_DIVISOR_HPP
#define MATH_DIVISOR_HPP

#include <algorithm>
#include <vector>

template<class T>
std::vector<T> divisor(T n) {
	std::vector<T> res;
	for (T i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			res.push_back(i);
			if (i * i != n) res.push_back(n / i);
		}
	}
	std::sort(res.begin(), res.end());
	return res;
}

#endif // MATH_DIVISOR_HPP

#ifndef MATH_SIEVE_OF_ERATOSTHENES
#define MATH_SIEVE_OF_ERATOSTHENES

#include <numeric>
#include <utility>
#include <vector>

class SieveOfEratosthenes {
private:
	std::vector<int> min_factor;

public:
	SieveOfEratosthenes(int n) : min_factor(n + 1) {
		std::iota(min_factor.begin(), min_factor.end(), 0);
		for (int p = 2; p * p <= n; ++p) {
			if (min_factor[p] < p) continue;
			for (int q = p * p; q <= n; q += p) {
				if (min_factor[q] == q) min_factor[q] = p;
			}
		}
	}

	bool is_prime(int n) { return n > 1 && min_factor[n] == n; }

	std::vector<std::pair<int, int>> factorize(int n) {
		std::vector<std::pair<int, int>> res;
		while (n > 1) {
			int p = min_factor[n];
			int exp = 0;
			while (min_factor[n] == p) {
				n /= p;
				++exp;
			}
			res.emplace_back(p, exp);
		}
		return res;
	}

	std::vector<int> divisor(int n) {
		std::vector<int> res{1};
		for (auto const &[p, exp] : factorize(n)) {
			int sz = res.size();
			for (int i = 0; i < sz; ++i) {
				int x = 1;
				for (int j = 0; j < exp; ++j) {
					x *= p;
					res.push_back(res[i] * x);
				}
			}
		}
		return res;
	}
};

#endif // MATH_SIEVE_OF_ERATOSTHENES

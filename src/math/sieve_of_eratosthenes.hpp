#ifndef MATH_SIEVE_OF_ERATOSTHENES
#define MATH_SIEVE_OF_ERATOSTHENES

#include <vector>

class SieveOfEratosthenes {
private:
	std::vector<bool> is_prime;
	std::vector<int> min_factor;

public:
	SieveOfEratosthenes(int n) : is_prime(n + 1, true), min_factor(n + 1, -1) {
		is_prime[0] = is_prime[1] = false;
		min_factor[1] = 1;
		for (int p = 2; p * p <= n; ++p) {
			if (!is_prime[p]) continue;
			min_factor[p] = p;
			for (int q = p * p; q <= n; q += p) {
				is_prime[q] = false;
				if (min_factor[q] == -1) min_factor[q] = p;
			}
		}
	}

	std::vector<bool> prime_table() { return is_prime; }

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

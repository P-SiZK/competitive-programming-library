#ifndef STRING_ROLLING_HASH_HPP
#define STRING_ROLLING_HASH_HPP

#include <chrono>
#include <cstdint>
#include <random>
#include <string>
#include <vector>

class RollingHash {
private:
	static std::uint64_t const MOD = (1ULL << 61) - 1;

	static std::uint64_t generate_base() noexcept {
		std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());
		std::uniform_int_distribution<std::uint64_t> rand(1, MOD - 1);
		return rand(mt);
	}

	static inline std::uint64_t base = generate_base();
	static inline std::vector<std::uint64_t> power;

	static void extend_power(int n) {
		if ((int)power.size() >= n + 1) return;
		if (power.empty()) power.assign({1});
		int prev_n = power.size();
		power.resize(n + 1, 1);
		for (int i = prev_n - 1; i < n; ++i) power[i + 1] = mul(power[i], base);
	}

	static std::uint64_t add(std::uint64_t a, std::uint64_t b) {
		a += b;
		if (a >= MOD) a -= MOD;
		return a;
	}

	static std::uint64_t mul(std::uint64_t a, std::uint64_t b) {
		std::uint64_t au = a >> 31;
		std::uint64_t al = a & ((1ULL << 31) - 1);
		std::uint64_t bu = b >> 31;
		std::uint64_t bl = b & ((1ULL << 31) - 1);
		std::uint64_t ul = al * bu + au * bl;

		std::uint64_t res = au * bu * 2;
		res += ul >> 30;
		res += (ul & ((1ULL << 30) - 1)) << 31;
		res += al * bl;
		return add(res >> 61, res & MOD);
	}

	std::vector<std::uint64_t> hash;

public:
	RollingHash() = default;

	void build(std::string const &s) {
		int n = s.size();
		extend_power(n);
		hash.assign(n + 1, 0);
		for (int i = 0; i < n; ++i) hash[i + 1] = add(mul(hash[i], base), s[i]);
	}

	std::uint64_t find(int l, int r) {
		return add(hash[r], MOD - mul(hash[l], power[r - l]));
	}
};

#endif // STRING_ROLLING_HASH_HPP

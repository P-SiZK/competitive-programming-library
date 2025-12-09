#ifndef DATASTRUCTURE_INTERVAL_SET
#define DATASTRUCTURE_INTERVAL_SET

#include <cassert>
#include <cstdint>
#include <iterator>
#include <limits>
#include <numeric>
#include <set>
#include <utility>

template<typename T>
class IntervalSet {
private:
	static constexpr T MIN = std::numeric_limits<T>::min();
	static constexpr T MAX = std::numeric_limits<T>::max();

	std::set<std::pair<T, T>> intervals;
	T adjacent_offset;

public:
	using iterator = typename std::set<std::pair<T, T>>::iterator;

	IntervalSet(bool enable_merge_adjacent = true) :
		intervals{
			{MIN, MIN},
            {MAX, MAX}
    },
		adjacent_offset(enable_merge_adjacent ? 1 : 0) {}

	iterator begin() const { return std::next(intervals.begin()); }

	iterator end() const { return std::prev(intervals.end()); }

	[[nodiscard]] iterator find(T x) const {
		auto it = std::prev(intervals.upper_bound({x, MAX}));
		return it->first <= x && x <= it->second ? it : end();
	}

	std::uint64_t insert(T x) { return insert(x, x); }

	std::uint64_t insert(T l, T r) { // [l, r]
		assert(l <= r);

		auto left_it = intervals.upper_bound({l, MAX});
		auto right_it = intervals.upper_bound({r + adjacent_offset, MAX});
		if (left_it != intervals.begin() &&
			l - adjacent_offset <= std::prev(left_it)->second)
			--left_it;

		std::uint64_t count =
			r - l + 1 -
			std::accumulate(left_it, right_it, std::uint64_t{0}, [](auto acc, auto x) {
				return acc + x.second - x.first + 1;
			});

		T ll = left_it->first;
		T rr = std::prev(right_it)->second;
		intervals.erase(left_it, right_it);
		if (ll < l) {
			count += l - ll;
			l = ll;
		}
		if (r < rr) {
			count += rr - r;
			r = rr;
		}

		intervals.emplace(l, r);
		return count;
	}

	std::uint64_t erase(T x) { return erase(x, x); }

	std::uint64_t erase(T l, T r) { // [l, r]
		assert(l <= r);

		auto left_it = intervals.upper_bound({l, MAX});
		auto right_it = intervals.upper_bound({r, MAX});
		if (left_it != intervals.begin() && l <= std::prev(left_it)->second) --left_it;
		if (left_it == right_it) return 0;

		std::uint64_t count =
			std::accumulate(left_it, right_it, std::uint64_t{0}, [](auto acc, auto x) {
				return acc + x.second - x.first + 1;
			});

		T ll = left_it->first;
		T rr = std::prev(right_it)->second;
		intervals.erase(left_it, right_it);
		if (ll < l) {
			count -= l - ll;
			intervals.emplace(ll, l - 1);
		}
		if (r < rr) {
			count -= rr - r;
			intervals.emplace(r + 1, rr);
		}

		return count;
	}

	[[nodiscard]] bool covered(T x) const { return covered(x, x); }

	[[nodiscard]] bool covered(T l, T r) const { // [l, r]
		assert(l <= r);
		auto it = std::prev(intervals.upper_bound({r, MAX}));
		return it->first <= l && r <= it->second;
	}

	[[nodiscard]] T mex(T x = 0) const {
		auto it = find(x);
		return it == end() ? x : it->second + 1;
	}
};

#endif // DATASTRUCTURE_INTERVAL_SET

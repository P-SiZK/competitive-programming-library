#ifndef VECTOR_COORDINATE_COMPRESSION
#define VECTOR_COORDINATE_COMPRESSION

#include <algorithm>
#include <vector>

template<class T>
class CoordinateCompression {
private:
	std::vector<T> x;

public:
	CoordinateCompression(std::vector<T> const &v) : x(v.size()) {
		std::partial_sort_copy(v.begin(), v.end(), x.begin(), x.end());
		x.erase(std::unique(x.begin(), x.end()), x.end());
	}

	[[nodiscard]] int size() const { return x.size(); }

	T operator[](int k) { return x[k]; }

	[[nodiscard]] int get(T const &v) const {
		return std::lower_bound(x.begin(), x.end(), v) - x.begin();
	}
};

#endif // VECTOR_COORDINATE_COMPRESSION

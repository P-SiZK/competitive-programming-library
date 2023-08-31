#ifndef DATASTRUCTURE_SPARSE_TABLE_HPP
#define DATASTRUCTURE_SPARSE_TABLE_HPP

#include <vector>

template<class T, class F>
class SparseTable {
private:
	std::vector<std::vector<T>> table;
	std::vector<int> log_table;
	F f;

public:
	SparseTable(std::vector<T> const &v, F f) : f(f) {
		int n = v.size();
		int h = 1;
		while ((1 << h) <= n) ++h;
		table.assign(h, std::vector<T>(n));
		log_table.assign(n + 1, 0);
		for (int i = 2; i <= n; ++i) log_table[i] = log_table[i >> 1] + 1;

		for (int i = 0; i < n; ++i) table[0][i] = v[i];
		for (int i = 1, k = 1; i < h; ++i, k <<= 1)
			for (int j = 0; j < n; ++j)
				table[i][j] = f(table[i - 1][j], table[i - 1][std::min(j + k, n - 1)]);
	}

	T query(int l, int r) { // [l, r)
		int k = log_table[r - l];
		return f(table[k][l], table[k][r - (1 << k)]);
	}
};

#endif // DATASTRUCTURE_SPARSE_TABLE_HPP

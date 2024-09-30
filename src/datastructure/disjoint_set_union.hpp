#ifndef DATASTRUCTURE_DISJOINT_SET_UNION_HPP
#define DATASTRUCTURE_DISJOINT_SET_UNION_HPP

#include <vector>

class DisjointSetUnion {
private:
	std::vector<int> rank, size, p;
	int num = 0;

public:
	DisjointSetUnion(int n) : rank(n), size(n, 1), p(n), num(n) {
		for (int i = 0; i < n; i++) p[i] = i;
	}

	bool same(int x, int y) { return root(x) == root(y); }

	void unite(int x, int y) {
		x = root(x), y = root(y);
		if (x == y) return;
		num--;
		if (rank[x] > rank[y]) {
			p[y] = x;
			size[x] += size[y];
		} else {
			p[x] = y;
			size[y] += size[x];
			if (rank[x] == rank[y]) rank[y]++;
		}
	}

	int root(int x) { return p[x] == x ? x : p[x] = root(p[x]); }

	int get_size(int x) { return size[root(x)]; }

	[[nodiscard]] int forest_size() const { return num; }
};

#endif // DATASTRUCTURE_DISJOINT_SET_UNION_HPP

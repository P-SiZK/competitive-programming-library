#ifndef DATASTRUCTURE_DISJOINT_SET_UNION_WITH_POTENTIAL
#define DATASTRUCTURE_DISJOINT_SET_UNION_WITH_POTENTIAL

#include <numeric>
#include <utility>
#include <vector>

template<class T>
class DisjointSetUnionWithPotential {
private:
	std::vector<int> rank, size, p;
	std::vector<T> pot;
	int num{};

public:
	DisjointSetUnionWithPotential(int n) : rank(n), size(n, 1), p(n), pot(n), num(n) {
		std::iota(p.begin(), p.end(), 0);
	}

	bool same(int x, int y) { return root(x) == root(y); }

	// potential(y) = potential(x) + d
	bool unite(int x, int y, T d) {
		d += potential(x);
		d -= potential(y);
		x = root(x);
		y = root(y);
		if (x == y) return d == 0;
		--num;
		if (rank[x] < rank[y]) {
			std::swap(x, y);
			d = -d;
		}
		if (rank[x] == rank[y]) ++rank[x];
		p[y] = x;
		pot[y] = d;
		size[x] += size[y];
		return true;
	}

	int root(int x) {
		if (p[x] == x) return x;
		int r = root(p[x]);
		pot[x] += pot[p[x]];
		return p[x] = r;
	}

	T potential(int x) {
		root(x);
		return pot[x];
	}

	T difference(int x, int y) { return potential(y) - potential(x); }

	int get_size(int x) { return size[root(x)]; }

	[[nodiscard]] int forest_size() const { return num; }
};

#endif // DATASTRUCTURE_DISJOINT_SET_UNION_WITH_POTENTIAL

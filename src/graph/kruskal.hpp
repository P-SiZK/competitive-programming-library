#include <algorithm>
#include <vector>

using namespace std;

class DisjointSet {
private:
	vector<int> rank, p;

public:
	DisjointSet(int n) {
		rank.assign(n, 0);
		p.assign(n, 0);
		for (int i = 0; i < n; i++) p[i] = i;
	}

	bool same(int x, int y) { return root(x) == root(y); }

	void unite(int x, int y) {
		x = root(x), y = root(y);
		if (x == y) return;
		if (rank[x] > rank[y]) {
			p[y] = x;
		} else {
			p[x] = y;
			if (rank[x] == rank[y]) rank[y]++;
		}
	}

	int root(int x) { return p[x] == x ? x : p[x] = root(p[x]); }
};

template<class T>
class Kruskal {
private:
	struct Edge {
		int from, to;
		T cost;

		Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}

		bool operator<(Edge const &a) { return cost < a.cost; }
	};

	int n;
	vector<Edge> g;

public:
	Kruskal(int n) : n(n) {}

	void add_edge(int from, int to, T cost) { g.emplace_back(from, to, cost); }

	T mst_cost() {
		T cost = 0;
		sort(g.begin(), g.end());
		DisjointSet ds(n);
		cost = 0;
		for (Edge const &e : g) {
			if (!ds.same(e.from, e.to)) {
				cost += e.cost;
				ds.unite(e.from, e.to);
			}
		}
		return cost;
	}
};

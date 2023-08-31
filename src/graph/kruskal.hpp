#ifndef GRAPH_KRUSKAL_HPP
#define GRAPH_KRUSKAL_HPP

#include "src/datastructure/disjoint_set.hpp"

#include <algorithm>
#include <vector>

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
	std::vector<Edge> g;

public:
	Kruskal(int n) : n(n) {}

	void add_edge(int from, int to, T cost) { g.emplace_back(from, to, cost); }

	T mst_cost() {
		T cost = 0;
		std::sort(g.begin(), g.end());
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

#endif // GRAPH_KRUSKAL_HPP

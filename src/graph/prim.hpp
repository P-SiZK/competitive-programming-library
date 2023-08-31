#ifndef GRAPH_PRIM_HPP
#define GRAPH_PRIM_HPP

#include <queue>
#include <utility>
#include <vector>

template<class T>
class Prim {
private:
	int n;
	std::vector<std::vector<std::pair<int, T>>> g;

public:
	Prim(int n) : n(n), g(n) {}

	void add_edge(int from, int to, T cost) {
		g[from].emplace_back(to, cost);
		g[to].emplace_back(from, cost);
	}

	T mst_cost() {
		T cost = 0;
		std::vector<bool> used(g.size());
		std::priority_queue<std::pair<T, int>,
							std::vector<std::pair<T, int>>,
							std::greater<>>
			pq;
		pq.emplace(0, 0);
		while (!pq.empty()) {
			auto [now_cost, now_v] = pq.top();
			pq.pop();
			if (used[now_v]) continue;
			used[now_v] = true;
			cost += now_cost;
			for (auto [nv, nw] : g[now_v]) pq.emplace(nw, nv);
		}
		return cost;
	}
};

#endif // GRAPH_PRIM_HPP

#ifndef GRAPH_DIJKSTRA_HPP
#define GRAPH_DIJKSTRA_HPP

#include <algorithm>
#include <functional>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

template<class T>
class Dijkstra {
private:
	static constexpr T INF = std::numeric_limits<T>::max();

	int s{};
	std::vector<std::vector<std::pair<int, T>>> g;
	std::vector<T> cost;
	std::vector<int> prevv;

public:
	Dijkstra(int n) : g(n), cost(n), prevv(n) {}

	void add_edge(int from, int to, T cost) { g[from].emplace_back(to, cost); }

	void build(int from) {
		s = from;
		cost.assign(g.size(), INF);
		prevv.assign(g.size(), -1);
		std::priority_queue<std::pair<T, int>,
							std::vector<std::pair<T, int>>,
							std::greater<>>
			pq;
		cost[s] = 0;
		pq.emplace(0, s);
		while (!pq.empty()) {
			auto [now_cost, now_v] = pq.top();
			pq.pop();
			if (cost[now_v] < now_cost) continue;
			for (auto [nv, nw] : g[now_v]) {
				if (cost[nv] > cost[now_v] + nw) {
					cost[nv] = cost[now_v] + nw;
					prevv[nv] = now_v;
					pq.emplace(cost[nv], nv);
				}
			}
		}
	}

	T distance(int to) { return cost[to]; }

	std::vector<int> shortest_path(int to) {
		std::vector<int> path;
		for (int v = to; v != -1; v = prevv[v]) path.push_back(v);
		std::reverse(path.begin(), path.end());
		return path;
	}

	bool is_unreachable(int to) { return cost[to] == INF; }
};

#endif // GRAPH_DIJKSTRA_HPP

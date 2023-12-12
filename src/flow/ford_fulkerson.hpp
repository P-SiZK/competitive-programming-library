#ifndef FLOW_FORD_FULKERSON_HPP
#define FLOW_FORD_FULKERSON_HPP

#include <algorithm>
#include <limits>
#include <vector>

template<class T>
class FordFulkerson {
private:
	struct Edge {
		int to, rev;
		T cap;

		Edge(int to, int cap, int rev) : to(to), rev(rev), cap(cap) {}
	};

	static constexpr T INF = std::numeric_limits<T>::max();

	std::vector<std::vector<Edge>> g;
	std::vector<int> used;

public:
	FordFulkerson(int n) : g(n), used(n) {}

	void add_edge(int from, int to, T cap, bool directed = true) {
		g[from].emplace_back(to, cap, g[to].size());
		g[to].emplace_back(from, (directed ? 0 : cap), g[from].size() - 1);
	}

	T dfs(int v, int t, T f) {
		if (v == t) return f;
		used[v] = true;
		for (auto &e : g[v]) {
			if (!used[e.to] && e.cap > 0) {
				T d = dfs(e.to, t, std::min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					g[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	T max_flow(int s, int t) {
		T flow = 0;
		while (true) {
			used.assign(g.size(), 0);
			T f = dfs(s, t, INF);
			if (f == 0) break;
			flow += f;
		}
		return flow;
	}
};

#endif // FLOW_FORD_FULKERSON_HPP

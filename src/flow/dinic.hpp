#ifndef FLOW_DINIC_HPP
#define FLOW_DINIC_HPP

#include <limits>
#include <queue>
#include <vector>

template<class T>
class Dinic {
private:
	struct Edge {
		int to, rev;
		T cap;

		Edge(int to, int cap, int rev) : to(to), rev(rev), cap(cap) {}
	};

	static constexpr T INF = std::numeric_limits<T>::max();

	std::vector<std::vector<Edge>> g;
	std::vector<int> level, iter;

public:
	Dinic(int n) : g(n), level(n), iter(n) {}

	void add_edge(int from, int to, T cap, bool directed = true) {
		g[from].emplace_back(to, cap, g[to].size());
		g[to].emplace_back(from, (directed ? 0 : cap), g[from].size() - 1);
	}

	void bfs(int s) {
		level.assign(g.size(), -1);
		std::queue<int> q;
		level[s] = 0;
		q.push(s);
		while (!q.empty()) {
			int const V = q.front();
			q.pop();
			for (auto &e : g[V]) {
				if (e.cap > 0 && level[e.to] == -1) {
					level[e.to] = level[V] + 1;
					q.push(e.to);
				}
			}
		}
	}

	T dfs(int v, int t, T f) {
		if (v == t) return f;
		for (int &i = iter[v]; i < (int)g[v].size(); ++i) {
			Edge &e = g[v][i];
			if (e.cap > 0 && level[v] < level[e.to]) {
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
			bfs(s);
			if (level[t] == -1) break;
			iter.assign(g.size(), 0);
			while (true) {
				T f = dfs(s, t, INF);
				if (f == 0) break;
				flow += f;
			}
		}
		return flow;
	}
};

#endif // FLOW_DINIC_HPP

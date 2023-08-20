#include <limits>
#include <vector>

using namespace std;

template<class T>
struct FordFulkerson {
	struct Edge {
		int to, rev;
		T cap;

		Edge(int to, T cap, int rev) : to(to), rev(rev), cap(cap) {}
	};

	const T INF = numeric_limits<T>::max();

	vector<vector<Edge>> G;
	vector<int> used;

	FordFulkerson(int n) : G(n), used(n) {}

	void add_edge(int from, int to, T cap, bool directed = true) {
		G[from].emplace_back(to, cap, G[to].size());
		G[to].emplace_back(from, (directed ? 0 : cap), G[from].size() - 1);
	}

	T dfs(int v, int t, T f) {
		if (v == t) return f;
		used[v] = true;
		for (auto &e : G[v]) {
			if (!used[e.to] && e.cap > 0) {
				T d = dfs(e.to, t, min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	T max_flow(int s, int t) {
		T flow = 0;
		while (true) {
			fill(used.begin(), used.end(), 0);
			T f = dfs(s, t, INF);
			if (f == 0) break;
			flow += f;
		}
		return flow;
	}
};

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

template<typename T>
struct FordFulkerson {
	struct Edge {
		int to, rev;
		T cap;

		Edge(int to, T cap, int rev) : to(to), cap(cap), rev(rev) {}
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

int main() {
	int V, E;
	cin >> V >> E;
	FordFulkerson<int> G(V);
	for (int i = 0; i < E; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		G.add_edge(u, v, c);
	}
	cout << G.max_flow(0, V - 1) << endl;

	return 0;
}

/*
	created: 2019-10-20
	https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
*/

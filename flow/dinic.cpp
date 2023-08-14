#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

template<class T>
struct Dinic {
	struct Edge {
		int to, rev;
		T cap;

		Edge(int to, int cap, int rev) : to(to), cap(cap), rev(rev) {}
	};

	const T INF = numeric_limits<T>::max();

	vector<vector<Edge>> G;
	vector<int> level, iter;

	Dinic(int n) : G(n), level(n), iter(n) {}

	void add_edge(int from, int to, T cap, bool directed = true) {
		G[from].emplace_back(to, cap, G[to].size());
		G[to].emplace_back(from, (directed ? 0 : cap), G[from].size() - 1);
	}

	void bfs(int s) {
		fill(level.begin(), level.end(), -1);
		queue<int> q;
		level[s] = 0;
		q.push(s);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (auto &e : G[v]) {
				if (e.cap > 0 && level[e.to] == -1) {
					level[e.to] = level[v] + 1;
					q.push(e.to);
				}
			}
		}
	}

	T dfs(int v, int t, T f) {
		if (v == t) return f;
		for (int &i = iter[v]; i < G[v].size(); ++i) {
			Edge &e = G[v][i];
			if (e.cap > 0 && level[v] < level[e.to]) {
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
			bfs(s);
			if (level[t] == -1) break;
			fill(iter.begin(), iter.end(), 0);
			while (true) {
				T f = dfs(s, t, INF);
				if (f == 0) break;
				flow += f;
			}
		}
		return flow;
	}
};

int main() {
	int V, E;
	cin >> V >> E;
	Dinic<int> G(V);
	for (int i = 0; i < E; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		G.add_edge(u, v, c);
	}
	cout << G.max_flow(0, V - 1) << endl;

	return 0;
}

/*
	created: 2019-10-23
	https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
*/

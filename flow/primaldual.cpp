#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <limits>

using namespace std;

//BEGIN
template <typename T, typename E>
struct PrimalDual {
	struct edge {
		int to, rev;
		T cap;
		E cost;

		edge() {}
		edge(int to, T cap, E cost, int rev) :to(to), cap(cap), cost(cost), rev(rev) {}
	};

	const E INF = numeric_limits<E>::max();
	vector<vector<edge> > G;
	vector<E> h, dist;
	vector<int> prevv, preve;

	PrimalDual() {}
	PrimalDual(int n) :G(n), h(n), dist(n), prevv(n), preve(n) {}

	void add_edge(int from, int to, T cap, E cost) {
		G[from].emplace_back(to, cap, cost, G[to].size());
		G[to].emplace_back(from, 0, -cost, G[from].size() - 1);
	}

	E min_cost_flow(int s, int t, T f) {
		E res = 0;
		priority_queue<pair<E, int>, vector<pair<E, int> >, greater<pair<E, int> > > pq;
		
		while (f > 0) {
			fill(dist.begin(), dist.end(), INF);
			pq.emplace(0, s);
			dist[s] = 0;
			while (!pq.empty()) {
				pair<E, int> p = pq.top();
				pq.pop();
				if (dist[p.second] < p.first) continue;
				for (int i = 0; i < G[p.second].size(); ++i) {
					edge& e = G[p.second][i];
					E ncost = dist[p.second] + e.cost + h[p.second] - h[e.to];
					if (e.cap > 0 && dist[e.to] > ncost) {
						dist[e.to] = ncost;
						prevv[e.to] = p.second; preve[e.to] = i;
						pq.emplace(dist[e.to], e.to);
					}
				}
			}
			if (dist[t] == INF) return -1;
			for (int v = 0; v < h.size(); ++v)
				if (dist[v] < INF) h[v] += dist[v];
			T d = f;
			for (int v = t; v != s; v = prevv[v]) d = min(d, G[prevv[v]][preve[v]].cap);
			f -= d;
			res += d * h[t];
			for (int v = t; v != s; v = prevv[v]) {
				edge& e = G[prevv[v]][preve[v]];
				e.cap -= d;
				G[v][e.rev].cap += d;
			}
		}
		return res;
	}
};
//END

int main() {
	int V, E, F; cin >> V >> E >> F;
	PrimalDual<int, int> G(V);
	for (int i = 0; i < E; ++i) {
		int u, v, c, d; cin >> u >> v >> c >> d;
		G.add_edge(u, v, c, d);
	}
	cout << G.min_cost_flow(0, V - 1, F) << endl;

	return 0;
}


/*
	created: 2020-01-06
	https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B
*/

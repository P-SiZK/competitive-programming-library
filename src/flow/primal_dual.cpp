#include <limits>
#include <queue>
#include <vector>

using namespace std;

template<class T, class E>
struct PrimalDual {
	struct Edge {
		int to, rev;
		T cap;
		E cost;

		Edge(int to, T cap, E cost, int rev) :
			to(to), rev(rev), cap(cap), cost(cost) {}
	};

	const E INF = numeric_limits<E>::max();
	vector<vector<Edge>> G;
	vector<E> h, dist;
	vector<int> prevv, preve;

	PrimalDual(int n) : G(n), h(n), dist(n), prevv(n), preve(n) {}

	void add_edge(int from, int to, T cap, E cost) {
		G[from].emplace_back(to, cap, cost, G[to].size());
		G[to].emplace_back(from, 0, -cost, G[from].size() - 1);
	}

	E min_cost_flow(int s, int t, T f) {
		E res = 0;
		priority_queue<pair<E, int>, vector<pair<E, int>>, greater<>> pq;

		while (f > 0) {
			fill(dist.begin(), dist.end(), INF);
			pq.emplace(0, s);
			dist[s] = 0;
			while (!pq.empty()) {
				pair<E, int> p = pq.top();
				pq.pop();
				if (dist[p.second] < p.first) continue;
				for (int i = 0; i < (int)G[p.second].size(); ++i) {
					Edge &e = G[p.second][i];
					E ncost = dist[p.second] + e.cost + h[p.second] - h[e.to];
					if (e.cap > 0 && dist[e.to] > ncost) {
						dist[e.to] = ncost;
						prevv[e.to] = p.second;
						preve[e.to] = i;
						pq.emplace(dist[e.to], e.to);
					}
				}
			}
			if (dist[t] == INF) return -1;
			for (int v = 0; v < (int)h.size(); ++v)
				if (dist[v] < INF) h[v] += dist[v];
			T d = f;
			for (int v = t; v != s; v = prevv[v])
				d = min(d, G[prevv[v]][preve[v]].cap);
			f -= d;
			res += d * h[t];
			for (int v = t; v != s; v = prevv[v]) {
				Edge &e = G[prevv[v]][preve[v]];
				e.cap -= d;
				G[v][e.rev].cap += d;
			}
		}
		return res;
	}
};

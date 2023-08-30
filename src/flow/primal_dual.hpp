#include <limits>
#include <queue>
#include <vector>

using namespace std;

template<class T, class E>
class PrimalDual {
private:
	struct Edge {
		int to, rev;
		T cap;
		E cost;

		Edge(int to, T cap, E cost, int rev) :
			to(to), rev(rev), cap(cap), cost(cost) {}
	};

	static constexpr E INF = numeric_limits<E>::max();

	vector<vector<Edge>> g;
	vector<E> h, dist;
	vector<int> prevv, preve;

public:
	PrimalDual(int n) : g(n), h(n), dist(n), prevv(n), preve(n) {}

	void add_edge(int from, int to, T cap, E cost) {
		g[from].emplace_back(to, cap, cost, g[to].size());
		g[to].emplace_back(from, 0, -cost, g[from].size() - 1);
	}

	E min_cost_flow(int s, int t, T f) {
		E res = 0;
		priority_queue<pair<E, int>, vector<pair<E, int>>, greater<>> pq;

		while (f > 0) {
			dist.assign(g.size(), INF);
			pq.emplace(0, s);
			dist[s] = 0;
			while (!pq.empty()) {
				auto [now_dist, now_v] = pq.top();
				pq.pop();
				if (dist[now_v] < now_dist) continue;
				for (int i = 0; i < (int)g[now_v].size(); ++i) {
					Edge &e = g[now_v][i];
					E ncost = dist[now_v] + e.cost + h[now_v] - h[e.to];
					if (e.cap > 0 && dist[e.to] > ncost) {
						dist[e.to] = ncost;
						prevv[e.to] = now_v;
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
				d = min(d, g[prevv[v]][preve[v]].cap);
			f -= d;
			res += d * h[t];
			for (int v = t; v != s; v = prevv[v]) {
				Edge &e = g[prevv[v]][preve[v]];
				e.cap -= d;
				g[v][e.rev].cap += d;
			}
		}
		return res;
	}
};

#include <algorithm>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

template<class T>
class Dijkstra {
private:
	static constexpr T INF = numeric_limits<T>::max();

	int s{};
	vector<vector<pair<int, T>>> g;
	vector<T> cost;
	vector<int> prevv;

public:
	Dijkstra(int n) : g(n), cost(n), prevv(n) {}

	void add_edge(int from, int to, T cost) { g[from].emplace_back(to, cost); }

	void build(int from) {
		s = from;
		cost.assign(g.size(), INF);
		prevv.assign(g.size(), -1);
		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> pq;
		cost[s] = 0;
		pq.push(make_pair(0, s));
		while (!pq.empty()) {
			auto [now_cost, now_v] = pq.top();
			pq.pop();
			if (cost[now_v] < now_cost) continue;
			for (auto [nv, nw] : g[now_v]) {
				if (cost[nv] > cost[now_v] + nw) {
					cost[nv] = cost[now_v] + nw;
					prevv[nv] = now_v;
					pq.push(make_pair(cost[nv], nv));
				}
			}
		}
	}

	T distance(int to) { return cost[to]; }

	vector<int> shortest_path(int to) {
		vector<int> path;
		for (int v = to; v != -1; v = prevv[v]) path.push_back(v);
		reverse(path.begin(), path.end());
		return path;
	}

	bool is_unreachable(int to) { return cost[to] == INF; }
};

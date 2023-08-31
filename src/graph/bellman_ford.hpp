#include <algorithm>
#include <limits>
#include <vector>

template<class T>
class BellmanFord {
private:
	struct Edge {
		int from, to;
		T cost;

		Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
	};

	static constexpr T INF = std::numeric_limits<T>::max();

	int n, s{};
	std::vector<Edge> g;
	std::vector<T> cost;
	std::vector<int> prevv;
	bool negative_cycle_flag{};

public:
	BellmanFord(int n) : n(n), cost(n), prevv(n) {}

	void add_edge(int from, int to, T cost) { g.emplace_back(from, to, cost); }

	void build(int from) {
		s = from;
		cost.assign(n, INF);
		prevv.assign(n, -1);
		cost[s] = 0;
		for (int i = 0; i < n; ++i) {
			for (Edge &e : g) {
				if (cost[e.from] == INF) continue;
				if (cost[e.to] > cost[e.from] + e.cost) {
					cost[e.to] = cost[e.from] + e.cost;
					prevv[e.to] = e.from;
					if (i == n - 1) {
						negative_cycle_flag = true;
						return;
					}
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

	bool has_negative_cycle() { return negative_cycle_flag; }
};

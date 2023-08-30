#include <queue>
#include <utility>
#include <vector>

using namespace std;

template<class T>
class Prim {
private:
	int n;
	vector<vector<pair<int, T>>> g;

public:
	Prim(int n) : n(n), g(n) {}

	void add_edge(int from, int to, T cost) {
		g[from].emplace_back(to, cost);
		g[to].emplace_back(from, cost);
	}

	T mst_cost() {
		T cost = 0;
		vector<bool> used(g.size());
		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> pq;
		pq.emplace(0, 0);
		while (!pq.empty()) {
			auto [now_cost, now_v] = pq.top();
			pq.pop();
			if (used[now_v]) continue;
			used[now_v] = true;
			cost += now_cost;
			for (auto [nv, nw] : g[now_v]) pq.emplace(nw, nv);
		}
		return cost;
	}
};

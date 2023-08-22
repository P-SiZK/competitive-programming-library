#include <limits>
#include <queue>
#include <vector>

using namespace std;

template<class T>
vector<T> dijkstra(int s, vector<vector<pair<int, T>>> &g) {
	const T INF = numeric_limits<T>::max();
	int const N = g.size();
	vector<T> cost(N, INF);
	vector<int> prevr(N, -1); // 経路復元用
	priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> pq;
	cost[s] = 0;
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		pair<T, int> p = pq.top();
		pq.pop();
		int now = p.second;
		if (cost[now] < p.first) continue;
		for (auto next : g[now]) {
			int nv = next.first;
			T nw = next.second;
			if (cost[nv] > cost[now] + nw) {
				cost[nv] = cost[now] + nw;
				prevr[nv] = now;
				pq.push(make_pair(cost[nv], nv));
			}
		}
	}
	return cost;
}

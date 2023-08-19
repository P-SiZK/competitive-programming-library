#include <queue>
#include <vector>

using namespace std;

template<class T>
T prim(vector<vector<pair<int, T>>> &G) {
	T cost = 0;
	const int N = G.size();
	vector<bool> used(G.size());
	priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> pq;
	pq.emplace(0, 0);
	while (!pq.empty()) {
		pair<T, int> p = pq.top();
		pq.pop();
		int now = p.second;
		if (used[now]) continue;
		used[now] = true;
		cost += p.first;
		for (auto e : G[now]) pq.emplace(e.second, e.first);
	}
	return cost;
}

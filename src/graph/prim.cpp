#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

template<class T>
T prim(vector<vector<pair<int, T>>> &G) {
	T cost = 0;
	const int N = G.size();
	vector<bool> used(G.size());
	priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> pq;
	pq.push(make_pair(0, 0));
	while (!pq.empty()) {
		pair<T, int> p = pq.top();
		pq.pop();
		int now = p.second;
		if (used[now]) continue;
		used[now] = true;
		cost += p.first;
		for (auto e : G[now]) pq.push(make_pair(e.second, e.first));
	}
	return cost;
}

int main() {
	int V, E;
	cin >> V >> E;
	vector<vector<pair<int, int>>> G(V);
	for (int i = 0; i < E; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		G[a].emplace_back(b, c);
		G[b].emplace_back(a, c);
	}
	cout << prim(G) << endl;

	return 0;
}

/*
	created: 2019-08-29
	https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
*/

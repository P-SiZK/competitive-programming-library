#include <limits>
#include <vector>

using namespace std;

template<class T>
struct Edge {
	int from, to;
	T cost;

	Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};

template<class T>
vector<T> bellman_ford(int s, int V, vector<Edge<T>> &G) {
	const T INF = numeric_limits<T>::max();
	vector<T> cost(V, INF);
	vector<int> prevr(V, -1); // 経路復元用
	cost[s] = 0;
	for (int i = 0; i < V; ++i) {
		for (Edge<T> e : G) {
			if (cost[e.from] == INF) continue;
			if (cost[e.to] > cost[e.from] + e.cost) {
				cost[e.to] = cost[e.from] + e.cost;
				prevr[e.to] = e.from;
				if (i == V - 1) return vector<T>();
			}
		}
	}
	return cost;
}

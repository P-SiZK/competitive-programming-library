#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct Edge {
	int from, to;
	T cost;

	Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};

template<typename T>
bool cmp(const Edge<T> &a, const Edge<T> &b) {
	return a.cost < b.cost;
}

class DisjointSet {
private:
	vector<int> rank, p;

public:
	DisjointSet() {}

	DisjointSet(int n) {
		rank.assign(n, 0);
		p.assign(n, 0);
		for (int i = 0; i < n; i++) p[i] = i;
	}

	bool same(int x, int y) { return root(x) == root(y); }

	void unite(int x, int y) {
		x = root(x), y = root(y);
		if (x == y) return;
		if (rank[x] > rank[y]) {
			p[y] = x;
		} else {
			p[x] = y;
			if (rank[x] == rank[y]) rank[y]++;
		}
	}

	int root(int x) { return p[x] == x ? x : p[x] = root(p[x]); }
};

template<typename T>
T kruskal(int V, vector<Edge<T>> &G) {
	sort(G.begin(), G.end(), cmp<T>);
	DisjointSet ds(V);
	T cost = 0;
	for (Edge<T> e : G) {
		if (!ds.same(e.from, e.to)) {
			cost += e.cost;
			ds.unite(e.from, e.to);
		}
	}
	return cost;
}

int main() {
	int V, E;
	cin >> V >> E;
	vector<Edge<int>> G;
	for (int i = 0; i < E; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		G.push_back(Edge<int>(a, b, c));
	}
	cout << kruskal(V, G) << endl;

	return 0;
}

/*
	created: 2019-08-30
	https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
*/

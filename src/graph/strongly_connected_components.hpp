#ifndef GRAPH_STRONGLY_CONNECTED_COMPONENTS
#define GRAPH_STRONGLY_CONNECTED_COMPONENTS

#include <algorithm>
#include <vector>

class StronglyConnectedComponents {
private:
	int n;
	std::vector<std::vector<int>> graph, rev_graph;
	std::vector<int> components;

	void dfs(int v, std::vector<bool> &used, std::vector<int> &order) {
		if (used[v]) return;
		used[v] = true;
		for (auto const &nv : graph[v]) dfs(nv, used, order);
		order.push_back(v);
	}

	void rev_dfs(int v, int id, std::vector<int> &components) {
		if (components[v] != -1) return;
		components[v] = id;
		for (auto const &nv : rev_graph[v]) rev_dfs(nv, id, components);
	}

public:
	StronglyConnectedComponents(int n) : n(n), graph(n), rev_graph(n), components(n) {}

	void add_edge(int from, int to) {
		graph[from].push_back(to);
		rev_graph[to].push_back(from);
	}

	int build() {
		std::vector<bool> used(n);
		std::vector<int> order(n);
		for (int i = 0; i < n; ++i) {
			if (used[i]) continue;
			dfs(i, used, order);
		}
		std::reverse(order.begin(), order.end());

		int cnt = 0;
		components.assign(n, -1);
		for (auto const &v : order) {
			if (components[v] != -1) continue;
			rev_dfs(v, cnt, components);
			++cnt;
		}

		return cnt;
	}

	int component_id(int v) { return components[v]; }
};

#endif // GRAPH_STRONGLY_CONNECTED_COMPONENTS

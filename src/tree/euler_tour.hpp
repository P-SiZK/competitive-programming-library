#ifndef TREE_EULER_TOUR_HPP
#define TREE_EULER_TOUR_HPP

#include "src/datastructure/sparse_table.hpp"

#include <optional>
#include <utility>
#include <vector>

class EulerTour {
private:
	std::vector<int> down, up, depth, terminal;
	std::optional<
		SparseTable<std::pair<int, int>, decltype(&std::min<std::pair<int, int>>)>>
		st;
	std::vector<std::vector<int>> G;

	void dfs(int v, int p, int d) {
		depth[terminal.size()] = d;
		down[v] = terminal.size();
		terminal.emplace_back(v);
		for (int u : G[v]) {
			if (u == p) continue;
			dfs(u, v, d + 1);
		}
		depth[terminal.size()] = d - 1;
		up[v] = terminal.size();
		terminal.emplace_back(p);
	}

public:
	EulerTour(int n) : down(n), up(n), depth(n << 1), G(n) {}

	void add_edge(int u, int v) {
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	void build(int root = 0) {
		terminal.clear();
		dfs(root, -1, 0);
		std::vector<std::pair<int, int>> dep(terminal.size());
		for (int i = 0; i < (int)terminal.size(); ++i) dep[i] = {depth[i], terminal[i]};
		st = SparseTable(dep, std::min<std::pair<int, int>>);
	}

	std::pair<int, int> index(int v) { return {down[v], up[v]}; };

	int parent(int u, int v) { return depth[down[u]] < depth[down[v]] ? u : v; }

	int child(int u, int v) { return depth[down[u]] < depth[down[v]] ? v : u; }

	int lca(int u, int v) {
		if (down[u] > down[v]) std::swap(u, v);
		return st.value().query(down[u], down[v] + 1).second;
	}

	template<class F>
	void query_vertex(int u, int v, F f) {
		int a = lca(u, v);
		f(down[a], down[u] + 1);
		f(down[a] + 1, down[v] + 1);
	}

	template<class F>
	void query_edge(int u, int v, F f) {
		int a = lca(u, v);
		f(down[a] + 1, down[u] + 1);
		f(down[a] + 1, down[v] + 1);
	}

	template<class T, class F>
	void update_vertex(int v, T x, F f) {
		f(down[v], x);
		f(up[v], -x);
	}

	template<class T, class F>
	void update_edge(int u, int v, T x, F f) {
		update_vertex(child(u, v), x, f);
	}
};

#endif // TREE_EULER_TOUR_HPP

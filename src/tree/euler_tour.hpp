#include <optional>
#include <vector>

class SparseTable {
private:
	std::vector<std::vector<std::pair<int, int>>> table;
	std::vector<int> log_table;

public:
	SparseTable(std::vector<std::pair<int, int>> const &v) {
		int const N = v.size();
		int h = 1;
		while ((1 << h) <= N) ++h;
		table.assign(h, std::vector<std::pair<int, int>>(N));
		log_table.assign(N + 1, 0);
		for (int i = 2; i <= N; ++i) log_table[i] = log_table[i >> 1] + 1;

		for (int i = 0; i < N; ++i) table[0][i] = v[i];
		for (int i = 1, k = 1; i < h; ++i, k <<= 1)
			for (int j = 0; j < N; ++j)
				table[i][j] = std::min(table[i - 1][j],
									   table[i - 1][std::min(j + k, N - 1)]);
	}

	std::pair<int, int> query(int l, int r) { // [l, r)
		int k = log_table[r - l];
		return std::min(table[k][l], table[k][r - (1 << k)]);
	}
};

class EulerTour {
private:
	std::vector<int> down, up, depth, terminal;
	std::optional<SparseTable> st;
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
		for (int i = 0; i < (int)terminal.size(); ++i)
			dep[i] = {depth[i], terminal[i]};
		st = SparseTable(dep);
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

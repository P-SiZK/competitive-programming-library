#include <optional>
#include <vector>

using namespace std;

class SparseTable {
private:
	vector<vector<pair<int, int>>> table;
	vector<int> log_table;

public:
	SparseTable(const vector<pair<int, int>> &v) {
		int n = v.size(), h = 1;
		while ((1 << h) <= n) ++h;
		table.assign(h, vector<pair<int, int>>(n));
		log_table.assign(n + 1, 0);
		for (int i = 2; i <= n; ++i) log_table[i] = log_table[i >> 1] + 1;

		for (int i = 0; i < n; ++i) table[0][i] = v[i];
		for (int i = 1, k = 1; i < h; ++i, k <<= 1)
			for (int j = 0; j < n; ++j)
				table[i][j] =
					min(table[i - 1][j], table[i - 1][min(j + k, n - 1)]);
	}

	pair<int, int> query(int l, int r) { // [l, r)
		int k = log_table[r - l];
		return min(table[k][l], table[k][r - (1 << k)]);
	}
};

class EulerTour {
private:
	vector<int> down, up, depth, terminal;
	optional<SparseTable> st;

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
	vector<vector<int>> G;

	EulerTour(int n) : down(n), up(n), depth(n << 1), G(n) {}

	void add_edge(int u, int v) {
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	void build(int root = 0) {
		terminal.clear();
		dfs(root, -1, 0);
		vector<pair<int, int>> dep(terminal.size());
		for (int i = 0; i < (int)terminal.size(); ++i)
			dep[i] = {depth[i], terminal[i]};
		st = SparseTable(dep);
	}

	pair<int, int> index(int v) { return {down[v], up[v]}; };

	int parent(int u, int v) { return depth[down[u]] < depth[down[v]] ? u : v; }

	int child(int u, int v) { return depth[down[u]] < depth[down[v]] ? v : u; }

	int lca(int u, int v) {
		if (down[u] > down[v]) swap(u, v);
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
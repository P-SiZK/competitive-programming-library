#include <iostream>
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

#include <tuple>

template<class T, class F>
struct SegmentTree { // 0-indexed
	int n;
	vector<T> tree;
	const F f; // function<T(T, T)>
	const T ti;

	SegmentTree(F f, T ti) : f(f), ti(ti) {}

	void init(int n_) {
		n = 1;
		while (n < n_) n *= 2;
		tree.assign(2 * n, ti);
	}

	void build(const vector<T> &v) {
		int n_ = v.size();
		init(n_);
		for (int i = 0; i < n_; ++i) tree[n + i] = v[i];
		for (int i = n - 1; i > 0; --i)
			tree[i] = f(tree[2 * i], tree[2 * i + 1]);
	}

	void update(int i, const T &x) {
		i += n;
		tree[i] = x;
		while (i >>= 1) tree[i] = f(tree[2 * i], tree[2 * i + 1]);
	}

	T find(int l, int r) { // [l, r)
		l += n, r += n;
		T ll = ti, rr = ti;
		while (l < r) {
			if (l & 1) ll = f(ll, tree[l++]);
			if (r & 1) rr = f(rr, tree[--r]);
			l >>= 1, r >>= 1;
		}
		return f(ll, rr);
	}

	T at(int i) { return tree[i + n]; }
};

void ABC294_G() {
	int n;
	cin >> n;
	vector<tuple<int, int, long long>> uvw(n - 1);
	EulerTour et(n);
	for (int i = 0; i < n - 1; ++i) {
		auto &[u, v, w] = uvw[i];
		cin >> u >> v >> w;
		--u, --v;
		et.add_edge(u, v);
	}
	et.build();
	SegmentTree st([](long long a, long long b) { return a + b; }, 0LL);
	vector<long long> weight(2 * n);
	for (int i = 1; i < n; ++i) {
		auto [u, v, w] = uvw[i - 1];
		auto [down, up] = et.index(et.child(u, v));
		weight[down] = w;
		weight[up] = -w;
	}
	st.build(weight);

	int q;
	cin >> q;
	while (q--) {
		int c;
		cin >> c;
		if (c == 1) {
			int i;
			long long w;
			cin >> i >> w;
			auto [u, v, _] = uvw[i - 1];
			auto update = [&](int i, long long x) { st.update(i, x); };
			et.update_edge(u, v, w, update);
		} else {
			int u, v;
			cin >> u >> v;
			long long res = 0;
			auto query = [&](int l, int r) { res += st.find(l, r); };
			et.query_edge(u - 1, v - 1, query);
			cout << res << endl;
		}
	}
}

/*
	created: 2023-08-19
	https://atcoder.jp/contests/abc294/tasks/abc294_g
*/

void VERTEX_ADD_PATH_SUM() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int &e : a) cin >> e;
	EulerTour et(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		et.add_edge(u, v);
	}
	et.build();
	SegmentTree st([](long long a, long long b) { return a + b; }, 0LL);
	vector<long long> weight(2 * n);
	for (int v = 0; v < n; ++v) {
		long long w = a[v];
		auto [down, up] = et.index(v);
		weight[down] = w;
		weight[up] = -w;
	}
	st.build(weight);

	while (q--) {
		int c;
		cin >> c;
		if (c == 0) {
			int p;
			long long x;
			cin >> p >> x;
			auto update = [&](int i, int val) { st.update(i, st.at(i) + val); };
			et.update_vertex(p, x, update);
		} else {
			int u, v;
			cin >> u >> v;
			long long res = 0;
			auto query = [&](int l, int r) { res += st.find(l, r); };
			et.query_vertex(u, v, query);
			cout << res << endl;
		}
	}
}

/*
	created: 2023-08-19
	https://judge.yosupo.jp/problem/vertex_add_path_sum
*/

void GRL_5_C() {
	int n;
	cin >> n;
	EulerTour et(n);
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int c;
			cin >> c;
			et.add_edge(i, c);
		}
	}
	et.build();

	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << et.lca(u, v) << endl;
	}
}

/*
	created: 2023-08-19
	https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
*/

int GRL_5_D() {
	int n;
	cin >> n;
	vector<int> p(n);
	EulerTour et(n);
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int c;
			cin >> c;
			p[c] = i;
			et.add_edge(i, c);
		}
	}
	et.build();
	SegmentTree st([](int a, int b) { return a + b; }, 0);
	st.init(2 * n);

	int q;
	cin >> q;
	while (q--) {
		int c;
		cin >> c;
		if (c == 0) {
			int v, w;
			cin >> v >> w;
			auto update = [&](int i, int x) { st.update(i, st.at(i) + x); };
			et.update_edge(v, p[v], w, update);
		} else {
			int u;
			cin >> u;
			int res = 0;
			auto query = [&](int l, int r) { res += st.find(l, r); };
			et.query_edge(u, 0, query);
			cout << res << endl;
		}
	}

	return 0;
}

/*
	created: 2023-08-19
	https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D
*/

int main() {
	// ABC294_G();
	// VERTEX_ADD_PATH_SUM();
	// GRL_5_C();
	// GRL_5_D();

	return 0;
}

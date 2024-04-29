#ifndef TREE_REROOTING_DP
#define TREE_REROOTING_DP

#include <utility>
#include <vector>

template<class T, class E, class F, class G>
class RerootingDP {
private:
	std::vector<std::vector<std::pair<int, E>>> graph;
	std::vector<T> dp1, dp2;
	F f; // function<T(T, T)>
	G g; // function<T(T, E)>
	T ti;

	void dfs(int v, int p) {
		for (auto const &[nv, e] : graph[v]) {
			if (nv == p) continue;
			dfs(nv, v);
			dp1[v] = f(dp1[v], g(dp1[nv], e));
		}
	}

	void dfs2(int v, int p, T ndp) {
		int size = graph[v].size();
		std::vector<T> lcum(size + 1, ti), rcum(size + 1, ti);

		for (int i = 0; i < size; ++i) {
			auto const &[nv, e] = graph[v][i];
			if (nv == p) lcum[i + 1] = f(lcum[i], g(ndp, e));
			else lcum[i + 1] = f(lcum[i], g(dp1[nv], e));
		}
		for (int i = size - 1; i >= 0; --i) {
			auto const &[nv, e] = graph[v][i];
			if (nv == p) rcum[i] = f(g(ndp, e), rcum[i + 1]);
			else rcum[i] = f(g(dp1[nv], e), rcum[i + 1]);
		}

		dp2[v] = lcum.back();
		for (int i = 0; i < size; ++i) {
			auto const &[nv, e] = graph[v][i];
			if (nv == p) continue;
			dfs2(nv, v, f(lcum[i], rcum[i + 1]));
		}
	}

public:
	RerootingDP(int n, F f, G g, T ti) :
		graph(n), dp1(n), dp2(n), f(f), g(g), ti(std::move(ti)) {}

	void add_edge(int u, int v, E const &e) {
		graph[u].emplace_back(v, e);
		graph[v].emplace_back(u, e);
	}

	std::vector<T> build(int v = 0, int p = -1) {
		dfs(v, p);
		return dp1;
	}

	std::vector<T> reroot(int v = 0, int p = -1) { return reroot(v, p, ti); }

	std::vector<T> reroot(int v, int p, T ndp) {
		dfs2(v, p, ndp);
		return dp2;
	}
};

#endif // TREE_REROOTING_DP

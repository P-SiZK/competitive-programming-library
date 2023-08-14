#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

template<typename T, typename E>
struct LazySegmentTree { // 0-indexed
	using F = function<T(T, T)>;
	using G = function<T(T, E)>;
	using H = function<E(E, E)>;

	int n, height;
	vector<T> tree;
	vector<E> lazy;
	const F f;
	const G g;
	const H h;
	const T ti;
	const E ei;

	LazySegmentTree(F f, G g, H h, T ti, E ei) :
		f(f), g(g), h(h), ti(ti), ei(ei) {}

	void init(int n_) {
		n = 1, height = 0;
		while (n < n_) n *= 2, ++height;
		tree.assign(2 * n, ti);
		lazy.assign(2 * n, ei);
	}

	void build(const vector<T> &v) {
		int n_ = v.size();
		init(n_);
		for (int i = 0; i < n_; ++i) tree[n + i] = v[i];
		for (int i = n - 1; i > 0; --i)
			tree[i] = f(tree[2 * i], tree[2 * i + 1]);
	}

	inline T reflect(int k) {
		return (lazy[k] == ei ? tree[k] : g(tree[k], lazy[k]));
	}

	inline void eval(int k) {
		if (lazy[k] == ei) return;
		lazy[2 * k] = h(lazy[2 * k], lazy[k]);
		lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
		tree[k] = reflect(k);
		lazy[k] = ei;
	}

	inline void thrust(int k) {
		for (int i = height; i > 0; --i) eval(k >> i);
	}

	inline void recalc(int k) {
		while (k >>= 1) tree[k] = f(reflect(2 * k), reflect(2 * k + 1));
	}

	void update(int s, int t, const E &x) { // [l, r)
		s += n, t += n;
		thrust(s), thrust(t - 1);
		int l = s, r = t;
		while (l < r) {
			if (l & 1) lazy[l] = h(lazy[l], x), ++l;
			if (r & 1) --r, lazy[r] = h(lazy[r], x);
			l >>= 1, r >>= 1;
		}
		recalc(s), recalc(t - 1);
	}

	T find(int s, int t) { // [l, r)
		s += n, t += n;
		thrust(s), thrust(t - 1);
		int l = s, r = t;
		T ll = ti, rr = ti;
		while (l < r) {
			if (l & 1) ll = f(ll, reflect(l++));
			if (r & 1) rr = f(rr, reflect(--r));
			l >>= 1, r >>= 1;
		}
		return f(ll, rr);
	}

	T at(int i) { return find(i, i + 1); }
};

void DSL_2_F() {
	int n, q;
	cin >> n >> q;
	auto f = [](int a, int b) { return min(a, b); };
	auto g = [](int a, int b) { return b; };
	LazySegmentTree<int, int> seg(f, g, g, INT_MAX, -1);
	seg.init(n);
	while (q--) {
		int com, s, t, x;
		cin >> com >> s >> t;
		if (com) cout << seg.find(s, t + 1) << endl;
		else cin >> x, seg.update(s, t + 1, x);
	}
}

/*
	created: 2019-12-05
	https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
*/

int main() {
	DSL_2_F();

	return 0;
}

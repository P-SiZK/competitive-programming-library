#include <vector>

using namespace std;

template<class T, class E, class F, class G, class H>
class LazySegmentTree { // 0-indexed
private:
	int n_{}, height{};
	vector<T> tree;
	vector<E> lazy;
	F f; // function<T(T, T)>
	G g; // function<T(T, E)>
	H h; // function<E(E, E)>
	T ti;
	E ei;

public:
	LazySegmentTree(F f, G g, H h, T ti, E ei) :
		f(f), g(g), h(h), ti(ti), ei(ei) {}

	void init(int n) {
		n_ = 1, height = 0;
		while (n_ < n) n_ *= 2, ++height;
		tree.assign(2 * n_, ti);
		lazy.assign(2 * n_, ei);
	}

	void build(vector<T> const &v) {
		int const N = v.size();
		init(N);
		for (int i = 0; i < N; ++i) tree[n_ + i] = v[i];
		for (int i = n_ - 1; i > 0; --i)
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

	void update(int s, int t, E const &x) { // [l, r)
		s += n_, t += n_;
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
		s += n_, t += n_;
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

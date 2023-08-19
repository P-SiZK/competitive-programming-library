#include <vector>

using namespace std;

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

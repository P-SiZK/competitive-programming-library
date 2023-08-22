#include <vector>

using namespace std;

template<class T, class F>
class SegmentTree { // 0-indexed
private:
	int n_{};
	vector<T> tree;
	F f; // function<T(T, T)>
	T ti;

public:
	SegmentTree(F f, T ti) : f(f), ti(ti) {}

	void init(int n) {
		n_ = 1;
		while (n_ < n) n_ *= 2;
		tree.assign(2 * n_, ti);
	}

	void build(vector<T> const &v) {
		int const N = v.size();
		init(N);
		for (int i = 0; i < N; ++i) tree[n_ + i] = v[i];
		for (int i = n_ - 1; i > 0; --i)
			tree[i] = f(tree[2 * i], tree[2 * i + 1]);
	}

	void update(int i, T const &x) {
		i += n_;
		tree[i] = x;
		while (i >>= 1) tree[i] = f(tree[2 * i], tree[2 * i + 1]);
	}

	T find(int l, int r) { // [l, r)
		l += n_, r += n_;
		T ll = ti, rr = ti;
		while (l < r) {
			if (l & 1) ll = f(ll, tree[l++]);
			if (r & 1) rr = f(rr, tree[--r]);
			l >>= 1, r >>= 1;
		}
		return f(ll, rr);
	}

	T at(int i) { return tree[i + n_]; }
};

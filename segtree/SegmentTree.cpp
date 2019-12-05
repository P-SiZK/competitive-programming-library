#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <climits>

using namespace std;

//BEGIN
template <typename T>
struct SegmentTree {
	using F = function<T(T, T)>;
	
	int n;
	vector<T> tree;
	const F f;
	const T ti;

	SegmentTree() {}
	SegmentTree(F f, T ti) :f(f), ti(ti) {}

	void init(int n_) {
		n = 1;
		while (n < n_) n *= 2;
		tree.assign(2 * n, ti);
	}

	void build(const vector<T>& v) {
		int n_ = v.size();
		init(n_);
		for (int i = 0; i < n_; ++i) tree[n + i] = v[i];
		for (int i = n - 1; i > 0; --i) tree[i] = f(tree[2 * i], tree[2 * i + 1]);
	}

	void update(int i, const T& x) {
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
//END

void DSL_2_A() {
	int n, q; cin >> n >> q;
	SegmentTree<int> seg([](int a, int b) { return min(a, b); }, INT_MAX);
	seg.init(n);
	while (q--) {
		int com, x, y; cin >> com >> x >> y;
		if (com) cout << seg.find(x, y + 1) << endl;
		else seg.update(x, y);
	}
}
/*
	created: 2019-11-30
	https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
*/
void DSL_2_B() {
	int n, q; cin >> n >> q;
	SegmentTree<long long> seg([](long long a, long long b) { return a + b; }, 0LL);
	seg.init(n);
	while (q--) {
		int com, x, y; cin >> com >> x >> y;
		--x;
		if (com) --y, cout << seg.find(x, y + 1) << endl;
		else seg.update(x, seg.at(x) + y);
	}
}
/*
	created: 2019-11-30
	https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
*/

int main() {
	//DSL_2_A();
	//DSL_2_B();

	return 0;
}

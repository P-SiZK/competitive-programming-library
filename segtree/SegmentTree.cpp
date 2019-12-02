#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <climits>

using namespace std;

//BEGIN
template <typename T>
struct  SegmentTree {
	using F = function<T(T, T)>;
	
	int n;
	vector<T> tree;
	const F f;
	const T t;

	SegmentTree() {}
	SegmentTree(F f, T t) :f(f), t(t) {}

	void init(int n_) {
		n = 1;
		while (n < n_) n <<= 1;
		tree.assign(2 * n, t);
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

	T find(const int& s, const int& t, int i, int l, int r) {
		if (r <= s || t <= l) return t;
		if (s <= l && r <= t) return tree[i];
		T tl = find(s, t, 2 * i, l, (l + r) >> 1);
		T tr = find(s, t, 2 * i + 1, (l + r) >> 1, r);
		return f(tl, tr);
	}
	T find(const int& s, const int& t) {
		return find(s, t, 1, 0, n);
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
		if (com) cout << seg.find(x, y) << endl;
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

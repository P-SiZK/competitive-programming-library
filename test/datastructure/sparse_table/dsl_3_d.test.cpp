// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D

#include "src/datastructure/sparse_table.cpp"

#include <iostream>
#include <vector>

int main() {
	int n, l;
	cin >> n >> l;
	vector<int> a(n);
	for (int &e : a) cin >> e;
	SparseTable st(a, [](int a, int b) { return min(a, b); });
	for (int i = 0; i <= n - l; ++i) {
		if (i) cout << " ";
		cout << st.query(i, i + l);
	}
	cout << endl;

	return 0;
}

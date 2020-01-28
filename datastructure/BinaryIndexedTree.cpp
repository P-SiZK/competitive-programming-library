#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct BIT {
	int n;
	vector<T> tree; // 1-indexed

	BIT() {}
	BIT(int n) :n(n), tree(n + 1) {}

	void add(int i, T x) {
		while (i <= n) {
			tree[i] += x;
			i += i & -i;
		}
	}

	T sum(int i) {
		T s(0); 
		while (i > 0) {
			s += tree[i];
			i -= i & -i;
		}
		return s;
	}

	T find(int l, int r) { // [l, r)
		return sum(r - 1) - sum(l - 1);
	}
};

long long InversionNumber(const vector<int>& v) {
	const int n = v.size();
	BIT<int> bit(n);
	long long res = 0;
	for (int i = 0; i < n; ++i) {
		res += i - bit.sum(v[i]);
		bit.add(v[i], 1);
	}
	return res;
}

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int& e : a) cin >> e;
	cout << InversionNumber(a) << endl;

	return 0;
}


/*
  created: 2020-01-28
  https://chokudai_s001.contest.atcoder.jp/tasks/chokudai_S001_j
*/

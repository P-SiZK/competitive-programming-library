#include <vector>

using namespace std;

template<class T>
class BinaryIndexedTree {
private:
	int n;
	vector<T> tree; // 1-indexed

public:
	BinaryIndexedTree(int n) : n(n), tree(n + 1) {}

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

template<class T>
long long inversion_number(vector<T> const &v) {
	int const N = v.size();
	BinaryIndexedTree<T> bit(N);
	long long res = 0;
	for (int i = 0; i < N; ++i) {
		res += i - bit.sum(v[i]);
		bit.add(v[i], 1);
	}
	return res;
}

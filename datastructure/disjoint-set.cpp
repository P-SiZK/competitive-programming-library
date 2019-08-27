#include <iostream>
#include <vector>

using namespace std;

//BEGIN
class DisjointSet {
private:
	vector<int> rank, size, p;
	int num = 0;;
public:
	DisjointSet() {}
	DisjointSet(int n) {
		num = n;
		rank.assign(n, 0);
		size.assign(n, 1);
		p.assign(n, 0);
		for (int i = 0; i < n; i++) p[i] = i;
	}

	bool same(int x, int y) {
		return root(x) == root(y);
	}

	void unite(int x, int y) {
		x = root(x), y = root(y);
		if (x == y) return;
		num--;
		if (rank[x] > rank[y]) {
			p[y] = x;
			size[x] += size[y];
		} else {
			p[x] = y;
			size[y] += size[x];
			if (rank[x] == rank[y]) rank[y]++;
		}
	}

	int root(int x) {
		return p[x]==x?x:p[x]=root(p[x]);
	}

	int get_size(int x) {
		return size[root(x)];
	}

	int forest_size() {
		return num;
	}
};
//END

int main() {
	int n, q; cin >> n >> q;
	DisjointSet ds(n);
	for (int i = 0; i < q; ++i) {
		int t, a, b; cin >> t >> a >> b;
		if (t == 0) ds.unite(a, b);
		else if (t == 1) {
			if (ds.same(a, b)) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
	
	return 0;
}


/*
	created: 2019-08-27
	https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A
*/

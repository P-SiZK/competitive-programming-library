// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D

#include "src/datastructure/binary_indexed_tree.hpp"

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &e : a) cin >> e;
	vector<int> a_cp(a);
	sort(a_cp.begin(), a_cp.end());
	map<int, int> mp;
	for (int i = 0; i < n; ++i) mp[a_cp[i]] = i + 1;
	for (int &e : a) e = mp[e];
	cout << inversion_number(a) << endl;

	return 0;
}

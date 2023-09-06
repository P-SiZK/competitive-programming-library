// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D

#include "src/vector/inversion_number.hpp"

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &e : a) cin >> e;
	cout << inversion_number(a) << endl;

	return 0;
}

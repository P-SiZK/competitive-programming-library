// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B

#include "src/string/rolling_hash.hpp"

#include <iostream>
#include <string>

using namespace std;

int main() {
	string t, p;
	cin >> t >> p;
	int n = p.size();

	RollingHash rht, rhp;
	rht.build(t);
	rhp.build(p);
	for (int i = 0; i <= (int)t.size() - n; ++i)
		if (rht.find(i, i + n) == rhp.find(0, n)) cout << i << endl;

	return 0;
}

// verification-helper: PROBLEM https://yukicoder.me/problems/no/3017

#include "src/datastructure/interval_set.hpp"

#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int ans = 0;
	IntervalSet<int> is;
	for (int i = 0; i < n; ++i) {
		int h;
		cin >> h;

		if (i % 2 == 0) ans += is.insert(1, h);
		else ans -= is.erase(1, h);

		cout << ans << endl;
	}

	return 0;
}

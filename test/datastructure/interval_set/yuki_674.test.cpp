// verification-helper: PROBLEM https://yukicoder.me/problems/no/674

#include "src/datastructure/interval_set.hpp"

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	long long d, q;
	cin >> d >> q;

	long long ans = 0;
	IntervalSet<long long> is;
	while (q--) {
		long long a, b;
		cin >> a >> b;

		is.insert(a, b);
		auto it = is.find(a);
		ans = max(ans, it->second - it->first + 1);

		cout << ans << endl;
	}

	return 0;
}

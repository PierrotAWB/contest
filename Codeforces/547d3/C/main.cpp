/**
 *    author: awb29
 *    created: Sat Apr 17 11:57:35 EDT 2021
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	
	cin.tie(0);
	int n;
	cin >> n;
	vector<long long> q(n);
	map<int, bool> m;

	long long high = -1e15;
	long long low = 1e15;
	long long acc = 0;
	m[0] = true;

	for (int i = 1; i <= n - 1; ++i) {
		cin >> q[i];
		acc += q[i];
		if (m.find(acc) != m.end()) {
			cout << "-1\n";
			return 0;
		}
		m[acc] = true;
		high = max(high, acc);
		low = min(low, acc);
	}

	if (high < 0) {
		if (high < -1) cout << "-1\n";
		else if (low < -n + 1) cout << "-1\n";
		else {
			acc = n;
			for (int i = 1; i <= n; ++i) {
				if (i > 1) cout << " ";
				cout << acc;
				acc += q[i];
			}
			cout << '\n';
		}
	} else if (low > 0) {
		if (low > 1) cout << "-1\n";
		else if (high > n - 1) cout << "-1\n";
		else {
			acc = 1;
			for (int i = 1; i <= n; ++i) {
				if (i > 1) cout << " ";
				cout << acc;
				acc += q[i];
			}
			cout << '\n';

		}
	} else if (high - low >= n) {
		cout << "-1\n";
	} else {
//  		cout << "DEBUG: high " << high << " low " << low << endl;
		acc = n - high;
		for (int i = 1; i <= n; ++i) {
			if (i > 1) cout << " ";
			cout << acc;
			if (i == n) break;
			acc += q[i];
		}
	}
}

/**
 *    author: awb29
 *    created: Fri Apr 30 01:50:23 PM EDT 2021 
**/
 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n + 1);

		vector<bool> t(n);

		int M = -1, m = n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			M = max(M, a[i]);
			if (a[i] < n) t[a[i]] = 1;
		}

		for (int j = 0; j < n; ++j) {
			if (t[j] == 0) {
				m = j;
				break;
			}
		}

		if (k == 0) {
			cout << n << '\n';
		} else if (m > M) {
			cout << k + M + 1 << '\n';
		} else {
			int target = (M + m + 1) / 2;
			bool found = false;
			for (auto u : a) {
				if (u == target) {
					found = true;
					break;
				}
			}
			if (found) {
				cout << n << '\n';
			} else {
				cout << n + 1 << '\n';
			}
		}
	}
}

/**
 *    author: awb29
 *    created: Fri Apr 16 13:45:19 EDT 2021
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<long long> b(n + 2);
		for (int i = 0; i < n + 2; ++i) {
			cin >> b[i];
		}
		sort(b.begin(), b.end());
		long long acc = 0;
		for (int i = 0; i <= n - 1; ++i) {
			acc += b[i];
		}
		
		if (b[n] == acc) { // max in sorted b is x
			for (int i = 0; i < n; ++i) {	
				if (i > 0) cout << " ";
				cout << b[i];
			}
			cout << '\n';
		} else {
			// Only possibility is if max in b is b_{n + 1}
			acc += b[n];
			long long target = acc - b[n + 1];
			if (target < b[0]) {
				cout << "-1\n";
				continue;
			}
			int idx = -1;
			for (int i = 0; i < n + 1; ++i) {
				if (b[i] == target) {
					idx = i;
					break;
				}
			}

			if (idx < 0) {
				cout << "-1\n";
			} else {
				bool not_first = false;
				for (int i = 0; i < n + 1; ++i) {
					if (i != idx) {
						if (not_first) {
							cout << " " << b[i];
						} else {
							cout << b[i];
							not_first = true;
						}
					}
				}
				cout << '\n';
			}
		}

	}
}

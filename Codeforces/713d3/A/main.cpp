/**
 *    author: awb29
 *    created: Thu Apr 15 21:05:35 EDT 2021
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	
	cin.tie(0);
	int tt, n;
	cin >> tt;
	while (tt--) {
		cin >> n;
		vector<int> v(n);
		for (int &e : v) cin >> e;

		vector<int> a = v;
		sort(a.begin(), a.end());

		for (int i = 0; i < n; ++i) {
			if (a[1] != v[i]) {
				cout << i + 1 << '\n';
				break;
			}
		}
	}
}

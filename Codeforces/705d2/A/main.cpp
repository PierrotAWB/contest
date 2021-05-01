/**
 *    author: awb29
 *    created: Fri Apr 30 04:53:35 PM EDT 2021 
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
		cout << n - (k + 1) / 2 << '\n';
		for (int i = (k + 1) / 2; i <= n; ++i) {
			if (i == k) continue;
			if (i > (k + 1) / 2) cout << ' ';
			cout << i;
		}
		cout << '\n';
	}
}

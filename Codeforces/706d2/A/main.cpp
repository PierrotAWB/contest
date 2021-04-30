/**
 *    author: awb29
 *    created: Fri Apr 30 01:27:21 PM EDT 2021 
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
		string s;
		cin >> n >> k;
		cin >> s;

		if (n % 2 == 0 && 2*k == n) {
			cout << "NO\n";
			continue;
		}

		int palinCount = 0;
		for (int i = 0; i < k; ++i) {
			if (s.at(i) == s.at(n - 1 - i)) ++palinCount;
			else break;
		}
		if (palinCount >= k) cout << "YES\n";
		else cout << "NO\n";
	}
}

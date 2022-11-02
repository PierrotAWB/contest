/**
 *    author: awb29
 *    created: Wed Nov  2 10:30:16 AM PDT 2022
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
		vector<int> v(n, 0);
		string s;
		for (int i = 0; i < n; ++i) cin >> v[i];
		cin >> s;

		string ans;

		map<int, char> d;
		for (int i = 0; i < n; ++i) {
			if (d.count(v[i]) == 0) {
				d[v[i]] = s.at(i);
			} else {
				if (d[v[i]] != s.at(i)) {
					ans = "NO";
					break;
				}
			}
			if (i == n - 1) {
				ans = "YES";
			}
		}
		cout << ans << endl;
	}
	return 0;
}

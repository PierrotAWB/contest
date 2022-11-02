/**
 *    author: awb29
 *    created: Wed Nov  2 01:40:04 PM PDT 2022
**/

#include <bits/stdc++.h>
using namespace std;
char a[600001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, last = -10000, ans = 0;
		char c;
		cin >> n >> c;
		cin >> (a + 1);
		for (int i = 1; i <= n; ++i) a[i + n] = a[i];
		for (int i = 2*n; i >= 0; --i) {
			if (a[i] == 'g') last = i;
			else if (a[i] == c) ans = max(ans, last - i);
		}
		cout << ans << '\n';
	}
	return 0;
}

/**
 *    author: awb29
 *    created: Tue Apr 20 11:07:28 EDT 2021
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n+1);
		map<int, int> f;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			++f[a[i] % m];
		}
		int count = (f[0] == 0) ? 0 : 1;
		for (int i = 1; i <= m / 2; ++i) {
			if (f.find(i) != f.end() || f.find(m - i) != f.end()) {
				if (abs(f[i] - f[m - i]) <= 1) {
					++count;
				} else {
					// differ by at least two 
					count += 1 + max(f[i], f[m - i]) - (min(f[i], f[m - i]) + 1);
				}
			}
		}
		cout << count << '\n';
	}
}

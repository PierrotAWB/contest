/**
 *    author: awb29
 *    created: Sun Apr 11 13:05:35 EDT 2021
**/

#include <bits/stdc++.h>
#define INFTY 10
using namespace std;

int main() {
	ios::sync_with_stdio(false);	
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];	
		}

		if (n == 1) {
			cout << a[0] << "\n";
			continue;
		}

		vector<pair<int, int>> best;

		if (a[0] == 0 && a[1] == 0) {
			best.push_back(make_pair(INFTY, 0));
			best.push_back(make_pair(0, 0));
		} else if (a[0] == 0 && a[1] == 1) {
			best.push_back(make_pair(INFTY, 0));
			best.push_back(make_pair(0, 1));
		} else if (a[0] == 1 && a[1] == 0) {
			best.push_back(make_pair(INFTY, 1));
			best.push_back(make_pair(1, 1));
		} else if (a[0] == 1 && a[1] == 1) {
			best.push_back(make_pair(INFTY, 1));
			best.push_back(make_pair(1, 2));
		}

		for (int i = 2; i < n; ++i) {
			int m = min(best[i - 1].second, best[i - 2].second);
			int f = min(best[i - 1].first + a[i], best[i - 2].first + a[i - 1] + a[i]);
			best.push_back(make_pair(m, f));
		}

		cout << min(best[n - 1].first, best[n - 1].second) << "\n";
	}
}

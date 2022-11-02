/**
 *    author: awb29
 *    created: Wed Nov  2 10:51:19 AM PDT 2022
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		/* cout << "CASE: " << tt << endl; */
		int n, q, n_even = 0;
		long long ans = 0;

		cin >> n >> q;
		vector<int> v(n, 0);

		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			if (v[i] % 2 == 0) ++n_even;
			ans += v[i];
		}

		for (int i = 0; i < q; ++i) {
			int t, x;
			cin >> t >> x;

			if (t == 0) ans += n_even * x;
			else ans += (n - n_even) * x;
			cout << ans << endl;
			if (x % 2 == 1) {
				if (t == 0) n_even = 0;
				else n_even = n;
				// Process rest together
				/* int curr = !t; // Does this work with ints? */
				/* for (int j = i + 1; j < q; ++j) { */
				/* 	cin >> t >> x; */
				/* 	if (t == curr) { */
				/* 		ans += x*n; */
				/* 		curr = !curr; */
				/* 	} */
				/* 	cout << ans << endl; */
				/* } */
				/* break; */
			}
		}
	}
	return 0;
}

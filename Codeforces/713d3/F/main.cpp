/**
 *    author: awb29
 *    created: Fri Apr 16 16:26:19 EDT 2021
**/

// WA on Test 2

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, c;
		cin >> n >> c;
		vector<long long> a(n + 1);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		vector<long long> b(n);
		for (int i = 1; i <= n - 1; ++i) {
			cin >> b[i];
		}
		// d[i] is the cost, in days, of advancing to job i (inclusive)
		vector<long long> d(n + 1); 
		vector<long long> leftover(n); // leftover[i] = how much money left over after buying ith course
		d[1] = leftover[1] = leftover[0] = 0;
		for (int i = 2; i < n; ++i) {
			leftover[i] = a[i] - a[i] % b[i];
		}
		int adjusted_course_cost;
		for (int i = 2; i <= n; ++i) {
			adjusted_course_cost = b[i - 1] - leftover[i - 2];
//  			cout << "i " << i << " adjusted cost " << adjusted_course_cost << endl;
			d[i] = d[i - 1] + (adjusted_course_cost + a[i - 1] - 1) / a[i - 1] + 1;
		}

		vector<long long> best(n + 1);
		assert(a[1] != 0);
		best[1] = (c + a[1] - 1) / a[1];

		int k = 2;
		for (; k <= n; ++k) {
			assert(b[k - 1] != 0);
			long long target = c - leftover[k - 1];
			assert(a[k] != 0);
			best[k] = min(best[k - 1], d[k] + (target + a[k] - 1) / a[k]);
		}
  		cout << best[k - 1] << '\n';
	}
}

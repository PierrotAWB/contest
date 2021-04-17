/**
 *    author: awb29
 *    created: Sat Apr 17 11:51:16 EDT 2021
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	
	cin.tie(0);
	int n;
	cin >> n;
	vector<bool> work(2 * n + 1);
	for (int i = 1; i <= n; ++i) {
		bool t;
		cin >> t;
		work[i] = work[i + n] = t;
	}
	int best = 0, cur = 0;
	for (int i = 1; i <= 2 * n; ++i) {
		if (work[i] == false) {
			cur = 0;
		} else {
			++cur;
			best = max(best, cur);
		}	
	}
	cout << best << '\n';
}

/**
 *    author: awb29
 *    created: Sat Apr 17 16:40:10 EDT 2021
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
		vector<char> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}

		int start = -1, end = -1;

		// Replace first and last
		for (int i = 0; i < n; ++i) {
			if (v[i] == '*') {
				v[i] == 'X';
				start = i;
				break;
			}
		}

		for (int i = n - 1; i >= 0; --i) {
			if (v[i] == '*') {
				v[i] == 'X';
				end = i;
				break;
			}
		}

		assert(start >= 0 && end >= 0);

		int count;
		if (end == start)
			count = 1;
		else
			count = 2;

		// Greedily set the X's as far apart as possible.
		for (int i = start; i + k < end; ++i) {
			int best = i + 1;
			for (int j = i + 1; j <= i + k; ++j)
				if (v[j] == '*') 
					best = max(best, j);
			v[best] = 'X';
			++count;
			i = best - 1;
		}

		cout << count << '\n';
	}
}

/**
 *    author: awb29
 *    created: Fri Apr 16 14:24:19 EDT 2021
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, l, r, s;
		cin >> n >> l >> r >> s;
		int t = r - l + 1;

		int min_sum = t * (t + 1) / 2;
		int max_sum = n * (n + 1) / 2 - (n - t) * (n - t + 1) / 2;
		
		if (s > max_sum || s < min_sum) {
			cout << "-1\n";
		} else if (n == t) {
			if (s == n * (n + 1) / 2) {
				for (int i = 1; i <= n; ++i) {
					if (i > 1) cout << " ";
					cout << i;
				}
				cout << '\n';
			} else cout << "-1\n";
		} else {
			// if in this branch, then n != t

			set<int> p;
			int delta = s - min_sum;

			int n_largest_growth = delta / (n - t);
			for (int i = 0; i < n_largest_growth; ++i) {
				p.insert(n - i);
			}
			int next = t - n_largest_growth;
			if (next >= 1) p.insert(next + delta % (n - t));
			for (int i = 1; i < next; ++i) {
				p.insert(i);
			}

			bool start = true;
			int j = 1;

//  			cout << "DEBUG: p: ";
//  			for (auto u : p) cout << u << " ";
//  			cout << endl;

			for (int i = 1; i < l; ++i) {
				if (find(p.begin(), p.end(), j) != p.end()) {
					++j;
					--i;	
				} else {
					if (!start) cout << " ";
					else start = false;
					cout << j++;
				}
			}
			for (auto u : p) {
				if (!start)	cout << " ";
				else start = false;
				cout << u;
			}
			for (int i = r + 1; i <= n; ++i) {
				if (find(p.begin(), p.end(), j) == p.end()) 
					cout << " " << j++;
				else {
					--i;
					++j;
				}
			}
			cout << '\n';
		}
	}
}

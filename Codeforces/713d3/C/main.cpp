/**
 *    author: awb29
 *    created: Fri Apr 16 12:01:54 EDT 2021
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	
	cin.tie(0);
	int tt; 
	cin >> tt;
	while (tt--) {
		int a, b; 
		cin >> a >> b;
		int n = a + b;
		vector<char> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}

		if (n == 1) {
			if (v[0] == '?') {
				if (b == 1) {
					cout << "1\n";
				} else {
					cout << "0\n";
				}
			} else {
				if (b == 1 && v[0] == '1' || 
						a == 1 && v[0] == '0')
					cout << v[0] << '\n';
				else cout << "-1\n";
			}
			continue;
		}

		int ones = 0, zeros = 0;
		bool impossible = false;

		// If odd, exclude middle
		for (int i = 0; i < n / 2; ++i) {
			if (v[i] == '1' && v[n - 1 - i] == '0' ||
					v[i] == '0' && v[n - 1 - i] == '1') { 
				impossible = true;
				break;
			} else if (v[n - 1 - i] == v[i]) {
				if (v[i] == '0') zeros += 2;
				else if (v[i] == '1') ones += 2;
			} else {
				// Exactly one of the two is a question mark.				
				if (v[i] == '?') {
					if (v[n - 1 - i] == '0') {
						v[i] = '0';
						zeros += 2;
					}
					else {
						v[i] = '1';
						ones += 2;
					}
				} else {
					if (v[i] == '0') {
						v[n - 1 - i] = '0';
						zeros += 2;
					}
					else {
						v[n - 1 - i] = '1';
						ones += 2;
					}
				}
			}
		}

		if (impossible) {
			cout << "-1\n";
			continue;
		}

		// Odd case
		if (n % 2 == 1) {
			if (v[(n - 1) / 2] == '1') ones += 1;
			else if (v[(n - 1) / 2] == '0') zeros += 1;
		}

		// cout << zeros << " " << ones << " " << endl;
		
		for (int i = 0; i < n / 2; ++i) {
			if (v[i] == '?') {
				if (a - zeros >= 2) {
					v[i] = v[n - 1 - i] = '0';
					zeros += 2;
				} else if (b - ones >= 2) {
					v[i] = v[n - 1 - i] = '1';
					ones += 2;
				} else {
					impossible = true;
					break;
				}
			}
		}

		if (zeros > a | ones > b) impossible = true;

		if (n % 2 == 1 && v[(n - 1) / 2] == '?') {
			if (a - zeros == 1) v[(n - 1) / 2] = '0';
			else if (b - ones == 1) v[(n - 1) / 2] = '1';
			else impossible = true;
		}

		if (impossible) {
			cout << "-1\n";
			continue;
		} else {
			for (auto u : v) cout << u;
			cout << '\n';
		}
	}
}

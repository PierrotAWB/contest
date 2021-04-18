/**
 *    author: awb29
 *    created: Sun Apr 18 13:46:12 EDT 2021
**/

#include <bits/stdc++.h>
using namespace std;

string inv(string s) {
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '1') s[i] = '0';
		else s[i] = '1';
	}
	return s;
}

int main() {
	ios::sync_with_stdio(false);	
	cin.tie(0);
	int tt;	
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		assert(a.size() == b.size());
		if (n % 2 == 1) {
			if (a[n - 1] != b[n - 1]) {
				cout << "NO\n";
				continue;
			} else if (n == 1) {
				cout << "YES\n";
				continue;
			}
		}
		int i = (n % 2 == 1) ? n - 3 : n - 2;
		int flips = 0;
		string seg;
		bool impossible = false;
		for (; i >= 0; i -= 2) {
			if (flips % 2 == 1) {
				seg = inv(a.substr(i, 2));
			} else seg = a.substr(i, 2);
			if (seg.compare(b.substr(i, 2)) == 0) continue;
			else if (seg.compare(inv(b.substr(i, 2))) == 0) {
				++flips;
				continue;
			}
			else {
				impossible = true;
				break;
			}
		}
		if (impossible) {
			cout << "NO\n";
		} else cout << "YES\n";
	}
}

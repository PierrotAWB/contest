/**
 *    author: awb29
 *    created: Wed Apr 28 07:45:06 PM EDT 2021 
**/
 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;	
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << 9 << '\n';
			continue;
		} else if (n == 2) {
			cout << 98 << '\n';
			continue;
		}
		cout << 98;
		int curr = 9;
		for (int i = 2; i < n; ++i) {
			cout << curr;
			curr = (curr + 1) % 10;
		}
		cout << '\n';
	}
}

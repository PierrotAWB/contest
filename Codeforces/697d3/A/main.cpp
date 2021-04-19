/**
 *    author: awb29
 *    created: Sun Apr 18 14:31:12 EDT 2021
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	
	cin.tie(0);
	int tt; 
	cin >> tt;
	while (tt--) {
		long long n;
		cin >> n;
		if (n % 2 == 1) {
			cout << "YES\n";
			continue;
		}
		while (n % 2 == 0) {
			n /= 2;
		}
		if (n == 1) {
			cout << "NO\n";
			continue;
		} else cout << "YES\n";
	}
}

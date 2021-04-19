/**
 *    author: awb29
 *    created: Sun Apr 18 14:35:29 EDT 2021
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
		bool success = false;
		if (n % 2021 == 0) {
			cout << "YES\n";
			continue;
		}

		while (n > 0) {
			if (n % 2020 == 0) {
				success = true;
				break;
			}
			n -= 2021;
		}

		if (n == 0) {
			printf("Shouldn't have happened, but n = %d", n);
		}
		if (success) cout << "YES\n";
		else cout << "NO\n";
	}
}

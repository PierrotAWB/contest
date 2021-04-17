/**
 *    author: awb29
 *    created: Sat Apr 17 11:45:14 EDT 2021
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	int k = m / n;
	if (n * k != m) {
		cout << "-1\n";
		return 0;
	}
	int moves = 0;
	while (k > 1) {
		if (k % 3 == 0) {
			k /= 3;
			++moves;
		} else if (k % 2 == 0) {
			k /= 2;
			++moves;
		} else {
			break;
		}
	}
	if (k == 1) cout << moves << '\n';
	else cout << "-1\n";
}

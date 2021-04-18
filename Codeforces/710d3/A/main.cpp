/**
 *    author: awb29
 *    created: Sat Apr 17 16:29:52 EDT 2021
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		long long n, m, x;	
		cin >> n >> m >> x;
	
		long long r = x % n;
		long long original_row;
		if (r == 0)
			original_row = n;
		else
			original_row = r;
		long long original_col = (x + n - 1) / n;
		cout << (original_row - 1) * m  + original_col << '\n';
	}
}

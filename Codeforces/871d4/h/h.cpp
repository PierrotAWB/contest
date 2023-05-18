/**
*    author: awb29
*    created: Thu May 18 08:42:29 EDT 2023
**/

#include <iostream>
#include <vector>

#define MAX_N 200000
#define N_BIN 64
#define M 1000000007
using namespace std;

int count_set_bits(int k) {
	int ret = 0;
	while (k > 0) {
		ret += k & 1;
		k = k >> 1;
	}
	return ret;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	vector< vector<int> > dp(n + 1, vector<int>(1 << 6, 0));
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		dp[i][a[i]] = 1;
		for (int mask = 0; mask < N_BIN; ++mask) {
			// Use the i-th
			dp[i][a[i] & mask] = (dp[i][a[i] & mask] + dp[i - 1][mask]) % M;

			// Don't use the i-th
			dp[i][mask] = (dp[i][mask] + dp[i - 1][mask]) % M;
		}
	}
	int acc = 0;
	for (int mask = 0; mask < N_BIN; ++mask) {
		if (k == count_set_bits(mask)) {
			acc = (acc + dp[n][mask]) % M;
		}
	}
	cout << acc << '\n';

}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}

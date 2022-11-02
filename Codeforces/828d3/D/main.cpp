/**
 *    author: awb29
 *    created: Wed Nov  2 02:54:54 PM PDT 2022
**/

#include <bits/stdc++.h>
using namespace std;

int count_pow2(int n) {
	int count = 0;
	while (n % 2 == 0) {
		++count;
		n /= 2;
	}
	return count;
}

// Returns greatest power of 2 not more than n.
int max_pow2(int n) {
	int ret = 1;
	while (2*ret <= n) {
		ret *= 2;
	}
	return ret;
}

void solve() {
	int n, total_pow2 = 0;
	cin >> n;

	vector<int> v(n + 1, 0);

	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
		total_pow2 += count_pow2(v[i]);
	}

	int needed = max(n - total_pow2, 0);

	if (needed == 0) {
		cout << "0\n";
		return;
	}

	int k = max_pow2(n);
	int l = count_pow2(k);
	int curr = 0;
	int count = 0;

	bool done = false;

	for (int i = k; i >= 2; i /= 2) {
		for (int j = 1; i * j <= n; j += 2) {
			if (needed - curr < l) break;
			++count;
			curr += l;
			if (curr == needed) {
				done = true;
				break;
			}
		}
		if (done) {
			break;
		}
		l -= 1;
	}

	if (curr < needed) {
		cout << "-1\n";
	} else cout << count << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}

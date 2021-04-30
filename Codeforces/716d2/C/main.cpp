/**
 *    author: awb29
 *    created: Fri Apr 30 12:49:31 PM EDT 2021 
**/
 
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v;
	long long prod = 1;
	for (int i = 1; i <= n - 1; ++i) {
		if (gcd(i, n) == 1) {
			v.push_back(i);
			prod = (prod * i) % n;
		}
	}
	if (prod != 1) cout << (int) v.size() - 1 << '\n';
	else cout << (int) v.size() << '\n';
	for (int i = 0; i < (int) v.size(); ++i) {
		if (i > 0) cout << ' ';
		if (v[i] == prod && prod != 1) continue;
		cout << v[i];
	}
	cout << '\n';
}

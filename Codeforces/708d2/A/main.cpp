/**
 *    author: awb29
 *    created: Mon Apr 19 08:49:21 EDT 2021
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		map<int, int> m;
		int n;
		cin >> n;
		vector<int> a(n + 1);
		vector<int> b;
		int foo;
		int j = 1;
		for (int i = 1; i <= n; ++i) {
			cin >> foo;
//  			printf("foo is %d\n", foo);
			a[j] = foo;
			++m[a[j]];
//  			printf("Element: %d, frequency: %d\n", a[j], m[a[j]]);
			if (m[a[j]] != 1) {
				b.push_back(a[j]);
			} else {
				++j;
			}
		}
		sort(a.begin() + 1, a.begin() + j);
		sort(b.begin(), b.end());
//  		cout << "DEBUGGING b" << endl;
  		for (auto u : b) {
//  			cout << u << " ";
  			a[j++] = u;
  		}
//  		cout << endl;
		for (int i = 1; i <= n; ++i) {
			if (i > 1) cout << " ";
			cout << a[i];
		}
		cout << '\n';
	}
}

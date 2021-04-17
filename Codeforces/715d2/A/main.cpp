/**
 *    author: awb29
 *    created: Sat Apr 17 14:18:55 EDT 2021
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
		vector<int> even;		
		vector<int> odd;

		for (int i = 1; i <= n; ++i) {
			int ai;
			cin >> ai;
			if (ai % 2 == 0) even.push_back(ai);
			else odd.push_back(ai);
		}
		
		for (int i = 0; i < even.size(); ++i) {
			if (i > 0) cout << " ";
			cout << even[i];
		}
		for (int i = 0; i < odd.size(); ++i) {
			if (even.size() > 0 || i > 0) cout << " ";
			cout << odd[i];
		}
		cout << '\n';
	}
}

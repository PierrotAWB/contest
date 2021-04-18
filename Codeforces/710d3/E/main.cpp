/**
 *    author: awb29
 *    created: Sun Apr 18 10:09:59 EDT 2021
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
		vector<int> q(n + 1);
		for (int i = 1; i <= n; ++i) cin >> q[i];
		vector<int> pmin(n + 1);
		vector<int> pmax(n + 1);
		pmin[1] = pmax[1] = q[1];

		priority_queue<int> pqmax;
		priority_queue<int, vector<int>, greater<int>> pqmin;
		for (int i = 1; i < q[1]; ++i) {
			pqmax.push(i);
			pqmin.push(i);
		}

		for (int i = 2; i <= n; ++i) {
			if (q[i] > q[i - 1]) {
				pmin[i] = pmax[i] = q[i]; // New max; fixed
				for (int j = q[i - 1] + 1; j < q[i]; ++j) {
					pqmax.push(j);
					pqmin.push(j);
				}
			} else {
				int a = pqmax.top(); pqmax.pop();	
				pmax[i] = a;

				int b = pqmin.top(); pqmin.pop();
				pmin[i] = b;
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (i > 1) cout << " ";
			cout << pmin[i];
		}
		cout << '\n';
		for (int i = 1; i <= n; ++i) {
			if (i > 1) cout << " ";
			cout << pmax[i];
		}
		cout << '\n';
	}
}

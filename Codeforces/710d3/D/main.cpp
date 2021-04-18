/**
 *    author: awb29
 *    created: Sun Apr 18 09:40:26 EDT 2021
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
		vector<int> a(n);
		map<int, int> M;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			++M[a[i]];
		}
		priority_queue<pair<int, int>> pq;
		for (auto u : M) pq.push(make_pair(u.second, u.first));
		int count = 0;
		while (pq.size() > 1) {
			auto ai = pq.top(); pq.pop();
			auto aj = pq.top(); pq.pop();
			--ai.first;
			--aj.first;
			count += 2;

			if (ai.first > 0) pq.push(ai);
			if (aj.first > 0) pq.push(aj);
		}

		if (pq.size() == 1) {
			cout << pq.top().first << '\n';
		} else {
			cout << "0\n";
		}
	}
}

/**
 *    author: awb29
 *    created: Sun Apr 18 10:52:13 EDT 2021
**/

#include <bits/stdc++.h>
using namespace std;

int dist(int r1, int c1, int r2, int c2) {
	// Right column can only be reached from (1, 1)
	if (r2 == c2) {
		assert(r1 == c1);
		return r2 - r1;
	}

	int activated_edges, tr, tc;
	tc = c2; 
	if ((r1 + c1) % 2 == 0) {
		if (r2 - c2 == r1 - c1) {
			// Need to immediately go right from an even r + c
			return r2 - r1;
		}
		else activated_edges = c2 - c1 + 1;
	} else {
		activated_edges = c2 - c1;
	}
	tr = r1 + activated_edges;

	if ((tr + tc) % 2 == 1) {
		return (r2 - tr	+ 1) / 2;
	} else {
		return (r2 - tr) / 2;
	}
}

int main() {
	ios::sync_with_stdio(false);	
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n; 
		cin >> n;
		vector<int> r(n + 1);
		for (int i = 1; i <= n; ++i) cin >> r[i];
		vector<int> c(n + 1);
		for (int i = 1; i <= n; ++i) cin >> c[i];
		vector<pair<int, int>> p;
		p.push_back(make_pair(1, 1));
		for (int i = 1; i <= n; ++i) {
			p.push_back(make_pair(r[i], c[i]));
		}
		sort(p.begin(), p.end());
		assert(p.size() == n + 1);
		int cost = 0;
		for (int i = 0; i <= n - 1; ++i) {
			cost += dist(p[i].first, p[i].second, p[i + 1].first, p[i + 1].second);
		}
		cout << cost << '\n';
	}
}

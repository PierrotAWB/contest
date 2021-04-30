/**
 *    author: awb29
 *    created: Fri Apr 30 04:28:14 PM EDT 2021 
**/
 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	cout.precision(10);
	while (tt--) {
		int n;
		cin >> n;

		vector<pair<long long, long long>> miners;
		vector<pair<long long, long long>> mines;

		long long x, y;

		for (int i = 0; i < 2*n; ++i) {
			cin >> x >> y;
			if (x == 0) miners.push_back(make_pair(abs(x), abs(y)));
			else mines.push_back(make_pair(abs(x), abs(y)));
		}

		sort(miners.begin(), miners.end());
		sort(mines.begin(), mines.end());

		double Esum = 0;

		auto dist = [&](long long x1, long long y1, long long x2, long long y2) {
			return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
		};

		for (int i = 0; i < n; ++i) {
			Esum += dist(miners[i].first, miners[i].second, mines[i].first, mines[i].second);
		}

		cout << Esum << '\n';
	}
}

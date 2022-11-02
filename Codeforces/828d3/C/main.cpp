/**
 *    author: awb29
 *    created: Wed Nov  2 11:28:05 AM PDT 2022
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
		char c;
		string s;
		cin >> n >> c >> s;
		s.append(s);

		if (c == 'g') {
			cout << "0\n";
			continue;
		}

		vector<int> g, cv;
		for (int i = 0; i < 2*n; ++i) {
			if (s.at(i) == 'g') g.push_back(i);
			else if (s.at(i) == c) cv.push_back(i);
		}

		int best = -1;
		for (auto u : cv) {
			int next = *upper_bound(g.begin(), g.end() - 1, u);
			/* cout << "DEBUG: " << u << " " << next << endl; */
			best = max(best, next - u);
		}

		cout << best << '\n';
	}
	return 0;
}

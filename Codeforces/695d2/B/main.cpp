/**
 *    author: awb29
 *    created: Wed Apr 28 08:05:20 PM EDT 2021 
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
		vector<int> a(n + 1);

		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}

		int intFact = 0;
		vector<int> indices;

		auto isHV = [&](int i) {
			if (i <= 1 || i >= n) return false;
			return (a[i] > a[i - 1] && a[i] > a[i + 1] ||
					a[i] < a[i - 1] && a[i] < a[i + 1]);
		};

		for (int i = 2; i <= n - 1; ++i) {
			if (isHV(i)) {
				++intFact; 
				indices.push_back(i);
			}
		}
		int best = intFact;

		for (auto idx : indices) {
			int curr = 0, lcurr = 0, rcurr = 0;
			for (int i = idx - 2; i <= idx + 1; ++i) if (isHV(i)) curr++;
			int temp = a[idx];
			a[idx] = a[idx - 1];
			for (int i = idx - 2; i <= idx + 1; ++i) if (isHV(i)) lcurr++;
			a[idx] = a[idx + 1];
			for (int i = idx - 2; i <= idx + 1; ++i) if (isHV(i)) rcurr++;
			int lowest = min(lcurr, rcurr);
			best = max(0, min(best, intFact - curr + lowest));
			a[idx] = temp;
		}
		cout << best << '\n';
	}
}

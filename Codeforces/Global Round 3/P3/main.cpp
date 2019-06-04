#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int p[300001], n;
vector<pair<int, int> > v;

void swap(int a, int b) {
	v.push_back(make_pair(a, b));
	int t = p[a];
	p[a] = p[b];
	p[b] = t;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> p[i];
	for (int i = 1; i <= n; ++i) {
		if (p[i] == i) continue;

		int ind = distance(p, find(p, p + n, i));
		// for (int j = 1; j <= n; ++j) {
	    // 	if (p[j] == i) {
		// 		ind = j;
		// 		break;
		// 	}
		// }

		if (abs(ind - i) >= n / 2) {
			swap(ind, i);
			continue;
		}
		int piv1;
		if (n - ind > ind - 1) {
			piv1 = n;
		} else {
			piv1 = 1;	
		}
		swap(piv1, ind);
		if (abs(i - piv1) >= n / 2) {
			swap(i, piv1);
			swap(piv1, ind);
		} else {
			int piv2;
			if (piv1 == n) piv2 = 1;
			else piv2 = n;
			swap(piv1, piv2);
			swap(piv2, i);
			swap(piv1, piv2);
			swap(piv1, ind);
		}
	}
	cout << v.size() << "\n";
	for (auto u : v) cout << u.first << " " << u.second << "\n";
	return 0;
}
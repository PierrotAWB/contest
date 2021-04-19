/**
 *    author: awb29
 *    created: Sun Apr 18 14:51:51 EDT 2021
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	
	cin.tie(0);
	int tt;	
	cin >> tt;
	while (tt--) {
		long long a, b, k;
		cin >> a >> b >> k;
		vector<int> boys(a + 1), girls(b + 1);
		vector<pair<int, int>> pairs(k + 1);
		for (int i = 0; i < k; ++i) {
			int boy_num;
			cin >> boy_num;
			++boys[boy_num];
			pairs[i + 1] = make_pair(boy_num, -1);
		}
		for (int i = 0; i < k; ++i) {
			int girl_num;
			cin >> girl_num;
			++girls[girl_num];
			pairs[i + 1].second = girl_num;
		}

		long long acc = 0;
		for (int i = 1; i <= k; ++i) {
			int boy = pairs[i].first;
			int girl = pairs[i].second;
			acc += k - boys[boy] - girls[girl] + 1;
		}
		cout << acc / 2 << '\n';
	}
}

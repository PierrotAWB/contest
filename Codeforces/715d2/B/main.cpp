/**
 *    author: awb29
 *    created: Sat Apr 17 14:29:07 EDT 2021
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
		vector<char> v(n);
		vector<int> Tidx(n); 
		vector<int> Midx(n);
		int t_count = 0, m_count = 0, t_m;
		int j = 0, k = 0;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			if (v[i] == 'T') {
				++t_count;
				Tidx[j++] = i;
			} else {
				++m_count;
				Midx[k++] = i;
			}
		}
		if (2 * m_count != t_count) {
			cout << "NO\n";
			continue;
		}
		bool impossible = false;
		for (int i = 0; i < m_count; ++i) { 
			if (Tidx[i] > Midx[i] || Midx[i] > Tidx[i + m_count]) {
				impossible = true;
				break;
			}
		}
		if (impossible) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
}

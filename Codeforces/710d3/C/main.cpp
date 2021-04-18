/**
 *    author: awb29
 *    created: Sat Apr 17 16:53:15 EDT 2021
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	
	cin.tie(0);
	int tt; string t;	
	// Input issues...
	getline(cin, t);
	tt = stoi(t);
	while (tt--) {
		string a, b;
		getline(cin, a);
		getline(cin, b);

//  		printf("a: %s, b: %s\n", a.c_str(), b.c_str());

		int best = a.size() + b.size();
		for (int i = 0; i < a.size(); ++i) {
			for (int d = 1; i + d - 1 < a.size(); ++d) {
				for (int k = 0; k + d  - 1 < b.size(); ++k) {
					// a[i .. i + d - 1] == b[k .. k + d - 1]?
					if (mismatch(a.begin() + i, a.begin() + i + d, b.begin() + k).first == a.begin() + i + d) {
						best = min(best, (int)a.size() + (int)b.size() - 2 * d);
					}
				}
			}
		}
		cout << best << '\n';
	}
}

/**
 *    author: awb29
 *    created: Sun Apr 18 13:33:08 EDT 2021
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		bool done = false;
		for (int i = 0; i < s.size() / 2; ++i) {
			if (s[i] != 'a') {
				s.insert(s.size() - i, "a");
				cout << "YES\n" << s << '\n';
				done = true;
				break;
			} else if (s[s.size() - 1 - i] != 'a') {
				s.insert(i, "a");
				cout << "YES\n" << s << '\n';
				done = true;
				break;
			}
		}
		if (done) continue;
		if (s.size() % 2 == 1 && s[(s.size() - 1)/ 2] != 'a') {
			s.insert(s.size() - 1, "a");
			cout << "YES\n" << s << '\n';
		}
		else cout << "NO\n";
	}
}

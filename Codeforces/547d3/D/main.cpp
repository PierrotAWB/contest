/**
 *    author: awb29
 *    created: Sat Apr 17 12:46:23 EDT 2021
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	
	cin.tie(0);
	int n;
	cin >> n;

	vector<pair<char, int>> l(n + 1);
	vector<pair<char, int>> r(n + 1);

	int lq = n, rq = n;
	int j = 1;

	for (int i = 1; i <= n; ++i) {
		char c;
		cin >> c;
		if (c == '?') {
			l[lq] = make_pair(c, i);
			--lq;
		} else {
			auto p = make_pair(c, i);
			l[j] = p;
			++j;
		}
	}
	j = 1;
	for (int i = 1; i <= n; ++i) {
		char c;
		cin >> c;
		if (c == '?') {
			r[rq] = make_pair(c, i);
			--rq;
		} else {
			auto p = make_pair(c, i);
			r[j] = p;
			++j;
		}
	}
//  	cout << "DEBUG: l: ";
//  	for (int i = 1; i <= n; ++i) cout << l[i].first << " ";
//  	cout << '\n';
//  	cout << "DEBUG: r: ";
//  	for (int i = 1; i <= n; ++i) cout << r[i].first << " ";
//  	cout << '\n';

	++lq; ++rq;
 //  	printf("lq: %d, rq: %d\n", lq, rq);

	sort(l.begin() + 1, l.begin() + lq);
	sort(r.begin() + 1, r.begin() + rq);

//  	cout << "DEBUG: sorted l: ";
//  	for (int i = 1; i <= n; ++i) cout << l[i].first << " " << l[i].second << " -- " ;
//  	cout << '\n';
//  	cout << "DEBUG: sorted r: ";
//  	for (int i = 1; i <= n; ++i) cout << r[i].first << " " << r[i].second << " -- ";
//  	cout << '\n';

	int Lq = lq, Rq = rq;

	int li = 1, ri = 1;
	vector<pair<int, int>> pairings;

	bool lreached = false, rreached = false;

	while (li <= n && ri <= n) {
//  		printf("li: %d, ri: %d\n", li, ri);
		assert(l[li].second > 0 && l[li].second <= n);
		assert(r[li].second > 0 && r[li].second <= n);
		if (li >= Lq && !lreached) {
			lreached = true;
			li = lq;
		}
		if (ri >= Rq && !rreached) {
			rreached = true;
			ri = rq;
		}

		if (l[li].first == r[ri].first || l[li].first == '?' || r[ri].first == '?') {
//  			printf("%c %d = l[li] === r[ri] = %c %d\n", l[li].first, l[li].second, r[ri].first, r[ri].second);
			pairings.push_back(make_pair(l[li++].second, r[ri++].second));
		} else if (l[li] < r[ri]) {
//  			printf("%c %d = l[li] < r[ri] = %c %d\n", l[li].first, l[li].second, r[ri].first, r[ri].second);
			if (rq <= n) {
				pairings.push_back(make_pair(l[li].second, r[rq++].second));
			} 
			++li;
		} else {
			if (lq <= n) {
				pairings.push_back(make_pair(l[lq++].second, r[ri].second));
			}
			++ri;
		}
	}

	cout << pairings.size() << '\n';
	for (auto u : pairings) cout << u.first << " " << u.second << '\n';
}

/**
 *    author: awb29
 *    created: Thu Apr 15 21:19:35 EDT 2021
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	
	cin.tie(0);
	int tt, n;
	cin >> tt;
	while (tt--) {
		cin >> n;
		vector<pair<int, int>> corner;
		char c;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> c;
				if (c == '*') corner.push_back(make_pair(i, j));
			}
		}
		// different row and column 
		if (corner[0].first != corner[1].first && 
				corner[0].second != corner[1].second) {
			corner.push_back(make_pair(corner[0].first, corner[1].second));
			corner.push_back(make_pair(corner[1].first, corner[0].second));
		} else if (corner[0].first == corner[1].first) {
			// same row
			if (corner[0].first == 0) {
				corner.push_back(make_pair(1, corner[0].second));
				corner.push_back(make_pair(1, corner[1].second));
			} else {
				corner.push_back(make_pair(corner[0].first - 1, corner[0].second));
				corner.push_back(make_pair(corner[0].first - 1, corner[1].second));
			}
		} else if (corner[0].second == corner[1].second) {
			// same column
			if (corner[0].second == 0) {
				corner.push_back(make_pair(corner[0].first, 1));
				corner.push_back(make_pair(corner[1].first, 1));
			} else {
				corner.push_back(make_pair(corner[0].first, corner[0].second - 1));
				corner.push_back(make_pair(corner[1].first, corner[1].second - 1));
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				pair<int, int> coord = make_pair(i, j);
				if (find(corner.begin(), corner.end(), coord) != corner.end()) cout << "*";
				else cout << ".";
			}
			cout << '\n';
		}
	}
}

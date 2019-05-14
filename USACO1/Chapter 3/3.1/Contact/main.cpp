/*
ID: andreww7
PROG: contact
LANG: C++11
*/

// From the 1998 IOI
// Simple brute-force suffices.

#include <algorithm>
#include <array>
#include <bitset>
#include <cstdio>
#include <deque>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map> 
#include <math.h>
#include <queue>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

map<string, int> m;
int A, B, N;

// Sort by frequency (decreasing), then by string length (increasing),
// then by binary value (increasing).
bool comp(pair<string, int> a, pair<string, int> b) {
	if (a.second != b.second) return a.second > b.second;
	if (a.first.length() != b.first.length()) return a.first.length() < b.first.length();
	for (int i = 0; i < a.first.length(); ++i) {
		if (a.first.at(i) > b.first.at(i)) return false;
		if (a.first.at(i) < b.first.at(i)) return true;
	}
	return false;
}

int main()
{
	ifstream fin("contact.in");
	ofstream fout("contact.out");

	fin >> A >> B >> N;

	string s = "", t;

	while (fin >> t) {
		s += t;
		if (t.length() < 80) break;
	}			

	int l = s.length();
	for (int i = 0; i < l; ++i) {
		for (int j = A; j <= B; ++j) {
			if (i + j - 1 >= l) break;
			try {
				++m[s.substr(i, j)];
			} catch (exception e) {
				m[s.substr(i, j)] = 1;	
			}
		}
	}

	vector<pair<string, int> > v;
	for (auto it = m.begin(); it != m.end(); ++it) {
		v.push_back(*it);
	}

	sort(v.begin(), v.end(), comp);

	// for (int i = 0; i < v.size(); ++i) {
	// 	cout << v[i].second << endl;
	// }

	l = v.size();

	int j = 0;
	for (int i = 0; i < N; ++i) {
		int f;

		if (j == v.size()) break;
		f = v[j].second;
		
		fout << f << endl;
		int t = 1;
		string temp = "";
		while (v[j].second == f) {
			if (t == 6) {
				fout << temp + v[j].first << endl;
				t = 1;
				temp = "";
				++j;
				continue;
			}	
			temp += v[j].first + " ";
			++t;
			++j;
			if (j == v.size()) break;
		}
		
		if (temp != "") fout << temp.substr(0, temp.length() - 1) + "\n";
	}
    return 0;
}

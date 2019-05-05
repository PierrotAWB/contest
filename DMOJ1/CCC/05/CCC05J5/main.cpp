#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <vector>

#define watch(x) cout << "CURRENT VALUE: " << x << endl;

using namespace std; 

set<string> dict;

bool isMonkey(string s) {
	if (s.at(0) != 'A' and s.at(0) != 'B') return false;
	if (s.at(0) == 'B' and s.at(s.length() - 1) != 'S') return false;
	if (dict.find(s) != dict.end()) return true;
	bool monkey;
	if (s.at(0) == 'A') {
		if (s.at(1) == 'N') {
			monkey = isMonkey(s.substr(2, s.length() - 2));
		} else {
			monkey = isMonkey(s.substr(1, s.length() - 1));
		}
	} else {
		monkey = isMonkey(s.substr(1, s.length() - 2));
	}
	if (monkey) {
		dict.insert(s);
	}
	return monkey;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	dict.insert("A");

	string s; 
	while (cin >> s) {
		if (s == "X") break;
		if (isMonkey(s)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
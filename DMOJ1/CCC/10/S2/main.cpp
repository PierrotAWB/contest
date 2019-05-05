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

int k;
string sequence, translation = "";
map<string, string> legend;

int main() {
	ios::sync_with_stdio(0);
	cin.tie();
	cin >> k; 
	for (int i = 0; i < k; i++) {
		string letter, code;
		cin >> letter >> code;
		legend[code] = letter; // map code to letter in order to translate
	}
	cin >> sequence;
	int index = 0; 
	while (index <= sequence.length() - 1) {
		for (int i = 1; i <= 25; i++) {
			// maximum 160 iterations! Plus, the length of the binary string is max 250-char, so
			// efficiency is of no concern here
			for (auto u : legend) { 
				if (sequence.substr(index, i) == u.first) {
					index += i;
					translation += u.second;
					goto next;
				}
			}
		}
		next:;
	}
	cout << translation << "\n";
	return 0;
}	
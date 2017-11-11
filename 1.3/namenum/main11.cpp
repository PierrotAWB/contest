#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string name[5000];
map<char, vector<string> > keypadMapping {{'2',{"A", "B", "C"}},
	{'3',{"D", "E", "F"}},
	{'4',{"G", "H", "I"}},
	{'5',{"J", "K", "L"}},
	{'6',{"M", "N", "O"}},
	{'7',{"P", "R", "S"}},
	{'8',{"T", "U", "V"}},
	{'9',{"W", "X", "Y"}}
};


vector<string> generateNameSpace(string name, int index) {
	vector<string> substring;
	vector<string> currentString;
	
	if (index == name.length() - 1) { // end of string; start returning
		for (int i = 0; i < 3; i++) {
			currentString.push_back(keypadMapping[name.at(index)][i]);
		}
		return currentString;
	}
	
	substring = generateNameSpace(name, index + 1);
	
	for (auto u : substring) {
		for (int i = 0; i < 3; i++) {
			currentString.push_back(keypadMapping[name.at(index)][i] + u);
		}
	}
	
	return currentString;
}

int main() {
	ofstream fout("namenum.out");
	ifstream fin("namenum.in");
	ifstream dict("dict.txt");
	
	 string acceptableName; int i = 0;
	 while (dict >> acceptableName) {
	 	name[i] = acceptableName;
	 	i++;
	 }
	
	string num; fin >> num;
	fout << num;
	
	vector<string> v = generateNameSpace(num, 0);
	
	for (auto u : v) {
		if (find(name, name + 5000, u) != name + 5000) cout << u << endl;
	}
	
	return 0;
}

/*
 ID: andreww7
 TASK: namenum
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string name[5000];
vector<string> keypadMapping[10];


vector<string> generateNameSpace(string strName, int index) {
	vector<string> substring;
	vector<string> currentString;
	
	if (index == strName.length() - 1) { // end of string; start returning
		for (int i = 0; i < 3; i++) {
			int numChar = (int) strName.at(index) - 48; // select appropriate letters from key.
			currentString.push_back(keypadMapping[numChar][i]);
		}
		return currentString;
	}
	
	substring = generateNameSpace(strName, index + 1);
	
	for (int i = 0; i < substring.size(); i++) {
		for (int j = 0; j < 3; j++) {
			int numChar = (int) strName.at(index) - 48;
			currentString.push_back(keypadMapping[numChar][j] + substring[i]);
		}
	}
	
	return currentString;
}

void initKeypad() {
	keypadMapping[2].push_back ("A");
	keypadMapping[2].push_back ("B");
	keypadMapping[2].push_back ("C");
	keypadMapping[3].push_back ("D");
	keypadMapping[3].push_back ("E");
	keypadMapping[3].push_back ("F");
	keypadMapping[4].push_back ("G");
	keypadMapping[4].push_back ("H");
	keypadMapping[4].push_back ("I");
	keypadMapping[5].push_back ("J");
	keypadMapping[5].push_back ("K");
	keypadMapping[5].push_back ("L");
	keypadMapping[6].push_back( "M");
	keypadMapping[6].push_back ("N");
	keypadMapping[6].push_back ("O");
	keypadMapping[7].push_back( "P");
	keypadMapping[7].push_back ("R");
	keypadMapping[7].push_back ("S");
	keypadMapping[8].push_back( "T");
	keypadMapping[8].push_back ("U");
	keypadMapping[8].push_back( "V");
	keypadMapping[9].push_back( "W");
	keypadMapping[9].push_back ("X");
	keypadMapping[9].push_back ("Y");
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
	
	initKeypad();
	
	string namenum; fin >> namenum;
	
	vector<string> v = generateNameSpace("4734", 0);
	
	for (int i = 0; i < v.size(); i++) {
		if (find(name, name + 5000, v[i]) != name + 5000) cout << v[i] << "\n";
	}
	
	return 0;
}

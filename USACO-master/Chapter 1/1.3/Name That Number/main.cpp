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
vector<char> keypadMapping[10];

bool isAcceptable(string compKey, string contender) { 
	if (compKey.length() != contender.length()) return false; 
	for (int i = 0; i < compKey.length(); i++) { 
		int numChar = (int)compKey.at(i) -  48;
		if (find(keypadMapping[numChar].begin(), keypadMapping[numChar].end(), contender.at(i)) == keypadMapping[numChar].end()) return false;
	}
	return true;
}

void initKeypad() { 
	keypadMapping[2].push_back ('A'); 
	keypadMapping[2].push_back ('B'); 
	keypadMapping[2].push_back ('C'); 
	keypadMapping[3].push_back ('D'); 
	keypadMapping[3].push_back ('E'); 
	keypadMapping[3].push_back ('F'); 
	keypadMapping[4].push_back ('G'); 
	keypadMapping[4].push_back ('H'); 
	keypadMapping[4].push_back ('I'); 
	keypadMapping[5].push_back ('J'); 
	keypadMapping[5].push_back ('K'); 
	keypadMapping[5].push_back ('L'); 
	keypadMapping[6].push_back( 'M'); 
	keypadMapping[6].push_back ('N'); 
	keypadMapping[6].push_back ('O'); 
	keypadMapping[7].push_back( 'P'); 
	keypadMapping[7].push_back ('R'); 
	keypadMapping[7].push_back ('S'); 
	keypadMapping[8].push_back( 'T'); 
	keypadMapping[8].push_back ('U'); 
	keypadMapping[8].push_back( 'V'); 
	keypadMapping[9].push_back( 'W'); 
	keypadMapping[9].push_back ('X'); 
	keypadMapping[9].push_back ('Y');  
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

	int acceptedCounter = 0;
	vector<string> acceptable; 

	for (int i = 0; i < 5000; i++) { 
		if (isAcceptable(namenum, name[i])) { 
			acceptedCounter++;
			acceptable.push_back(name[i]);
		}
	}

	if (acceptedCounter == 0) fout << "NONE\n";
	else { 
	 	sort(acceptable.begin(), acceptable.end()); 
		for (int i = 0; i < acceptable.size(); i++){ 
			fout << acceptable[i] << "\n";
		}
	}
	return 0;
}
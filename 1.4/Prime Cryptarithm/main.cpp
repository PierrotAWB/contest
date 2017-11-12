/*
ID: andreww7
TASK: crypt1
LANG: C++11
*/

#include <algorithm>
#include <fstream>
#include <math.h>
#include <string> 
#include <vector> 
 
#include <iostream>

using namespace std; 

// global var's and constants
vector<string> dig;
const int GROUPING_LENGTH = 5;

// function declaration
vector<string> generateGrouping(int index);
bool hasCorrectDigits (int n);
bool isSolution(string s);

int main() {
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out"); 

	int N, solutionCounter = 0;
	fin >> N; 

	for (int i = 0; i < N; i++) { 
		string s; 
		fin >> s;
		dig.push_back(s);
	}

	vector<string> grouping = generateGrouping(1);

	for (int i = 0; i < grouping.size(); i++) { 
		if (isSolution(grouping[i])) {
			solutionCounter++;
			cout << grouping[i] << endl;
		}
		// cout << grouping[i] << " ";
	}

	fout << solutionCounter << "\n";

	return 0; 
}

// function definitions
vector<string> generateGrouping(int index) { 
	vector<string> currentGrouping; 
	if (index == GROUPING_LENGTH) { 
		for (int i = 0 ; i < dig.size(); i++) { 
			currentGrouping.push_back(dig[i]);
		}
		return currentGrouping;
	}

	vector<string> previousGrouping = generateGrouping(index + 1);
	for (int i = 0; i < previousGrouping.size(); i++) { 
		for (int j = 0; j < dig.size(); j++) { 
				currentGrouping.push_back(dig[j] + previousGrouping[i]);
		}
	}

	return currentGrouping;
}

bool hasCorrectDigits(int n) { 
	string s = to_string(n);
	for (int i = 0; i < s.length(); i++) { 
		if (find(dig.begin(), dig.end(), s.substr(i, 1)) == dig.end()) return false; 
	}
	return true;
}

bool isSolution(string s) { // does the string of length 5 solve the desired crtpytogram?
	// if (s == "22222") cout << "OK ";
	int multiplier = stoi(s.substr(0, 3));
	int multiplicand = stoi(s.substr(3, 2));

	div_t divRes = div(multiplicand, 10); 

	int p1 = divRes.rem * multiplier;
	int p2 = divRes.quot * multiplier; 

	if (!hasCorrectDigits(p1) || !hasCorrectDigits(p2)) return false;
	if (p1 >= 1000 || p2 >= 1000) return false;

	int sum = p1 + 10 * p2; 

	// if (s == "22222") cout << p1 << " " << p2 << " " << sum;
	
	if (!hasCorrectDigits(sum)) return false;

	// cout << p1 << " " <<  p2 << " " << sum << " ";

	return true;
}
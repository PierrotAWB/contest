/*
ID: andreww7
TASK: dualpal
LANG: C++
*/

#include <math.h>
#include <string>
#include <fstream>
using namespace std;

// global variables and constants

string m[10]; // in place of "to_string", which is not available to the judge, use a manual lookup table

// function declarations 
string convertBase(int b, int n);
void initTable();
bool isDualPal(int k);
bool isPal(string s); 

int main() { 
	ifstream fin("dualpal.in"); 
	ofstream fout("dualpal.out");
	initTable();

	int N, S; 
	fin >> N >> S; 

	int dualPalCounter = 0, candidate = S + 1;
	while (dualPalCounter < N) { 
		if (isDualPal(candidate)) { 
			dualPalCounter++;
			fout << candidate << "\n";
		}
		candidate++;
	}

	return 0;
}

// function definitions
string convertBase(int b, int n) { 
	int highestPower = floor(log(n) / (double) log(b));
	string result = "";

	for (int i = highestPower; i >= 0; i--) { 
		if (pow(b, i) > n) { 
			result += "0";
			continue;
		}
		int d = n / pow(b, i); // d is the base 10 representation of the digit to be inserted
		result += m[d];
		n -= d * pow(b, i);
	}
	return result;
}

void initTable() { 
	m[0] = "0";
	m[1] = "1"; m[2] = "2"; m[3] = "3";
	m[4] = "4"; m[5] = "5"; m[6] = "6"; 
	m[7] = "7"; m[8] = "8"; m[9] = "9";
}

bool isDualPal(int k) { 
	int nBases = 0; 
	for (int i = 2; i <= 10; i++) { 
		if (isPal(convertBase(i, k))) nBases++;
	}
	if (nBases >= 2) return true; 
	return false;
}

bool isPal(string s) { 
	int L = s.length(); 
	for (int i = 0; i < L / 2; i++) { 
		if (s.at(i) != s.at(L - i - 1)) return false;
	}
	return true;
}
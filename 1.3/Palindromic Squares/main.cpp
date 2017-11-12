/*
ID: andreww7
TASK: palsquare
LANG: C++
*/

#include <string>
#include <fstream>
#include <math.h>
using namespace std; 

// global variables and constants
string m[20];

// function declarations
string convertBase(int b, int n);
bool isPalindromic(string s);
void initTable();

int main() { 
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out"); 

	initTable();

	int B; 
	fin >> B; 

	for (int N = 1; N <= 300; N++) { 
		if (isPalindromic(convertBase(B, pow(N, 2)))){ 
			fout << convertBase(B, N) << " " << convertBase(B, pow(N, 2)) << "\n";
		}
	}

	return 0;
}

// function definitions
string convertBase(int b, int n) { // convert n (in decimal rep) to base b.
	int highestPow = floor(log(n)/(double)log(b));
	string result = "";

	for (int i = highestPow; i >= 0; i--) { 
		if (pow(b, i) > n) { 
			result += "0"; 
			continue;
		}
		int d = n / pow(b, i);// the decimal representation of the digit to be inserted.
		result += m[d];
		n -= d * pow(b, i);
	}
	return result;
}

void initTable() { 
	m[1] = "1"; m[2] = "2"; m[3] = "3";
	m[4] = "4"; m[5] = "5"; m[6] = "6"; 
	m[7] = "7"; m[8] = "8"; m[9] = "9";
	m[10] = "A"; m[11] = "B"; m[12] = "C"; 
	m[13] = "D"; m[14] = "E"; m[15] = "F"; 
	m[16] = "G"; m[17] = "H"; m[18] = "I";
	m[19] = "J"; m[20] = "K";
}

bool isPalindromic(string s) { 
	int L = s.length(); 
	for (int i = 0; i < L / (double) 2; i++) { 
		if (s.at(i) != s.at(L - i - 1)) return false;
	}

	return true;
}
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

using namespace std; 

vector<int> dig;

bool isSol(int i, int j);
bool hasCorrectDigits(int k);
bool hasZero(int l);

int main() { 
	ifstream fin("crypt1.in"); 
	ofstream fout("crypt1.out");

	int N, solutionCounter = 0; 
	fin >> N; 

	for (int i = 0; i < N; i++) { 
		int k; 
		fin >> k; 
		dig.push_back(k);
	}

	for (int i = 101; i <= 999; i++) { 
		for (int j = 11; j <= 99; j++) { 
			if (!hasZero(i) && !hasZero(j)) { 
				if (isSol(i, j)) solutionCounter++;
			}
		}
	}

	fout << solutionCounter << "\n";
	return 0;
}

bool hasZero(int l) { 
	string s = to_string(l); 
	for (int i = 0; i < s.length(); i++) {
		if (s.substr(i, 1) == "0") return true;
	}
	return false;
}

bool hasCorrectDigits(int k) { 
	string s = to_string(k); 
	for (int i = 0; i < s.length(); i++) { 
		if (find(dig.begin(), dig.end(), stoi(s.substr(i, 1))) == dig.end()) return false;
	}
	return true;
}

bool isSol(int i, int j) { 
	if (!hasCorrectDigits(i) || !hasCorrectDigits(j)) return 0;

	div_t divRes = div(j, 10);

	if (!hasCorrectDigits((int) i * divRes.rem) or !hasCorrectDigits((int) i * divRes.quot)) return false; 
	if (i * divRes.rem > 1000 || i * divRes.quot > 1000) return false;

	int sum = i * divRes.rem + 10 * i * divRes.quot; 
	if (!hasCorrectDigits(sum)) return false; 
	return true;
}
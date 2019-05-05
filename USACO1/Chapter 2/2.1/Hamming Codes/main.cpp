/*
ID: andreww7
TASK: hamming
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std; 

int N, B, D;
vector<int> code;

// vector<string> generateBitstring(int length);
string toBinary(int n);
int hammingDistance(int a, int b);

int main() { 
	ifstream fin("hamming.in");
	fin >> N >> B >> D; // B only serves to provide an upper bound on the search (2 ^ (B + 1) - 1)
	fin.close();

	code.push_back(0);
	for (int i = 1; i < pow(2, B + 1); i++) {
		for (int j = 0; j < code.size(); j++) {
			if (hammingDistance(i, code[j]) < D)
				break;
			if (hammingDistance(i, code[j] >= D) && j == code.size() - 1)
				code.push_back(i);
		}
	}

	ofstream fout("hamming.out");
	for (int i = 0; i < N / 10; i++) {
		for (int j = 0; j < 9; j++) {
			fout << code[10*i + j] << " ";
		}
		fout << code[10*i + 9] << "\n";
	}
	for (int i = 10 * (N / 10); i < N - 1; i++)
		fout << code[i] << " ";
	if (N % 10 != 0) fout << code[N - 1] << "\n";
	fout.close();
	return 0;
}

int hammingDistance(int a, int d) {
	// assume a and b are bitstrings
	int c = a ^ d; 
	string bitC = toBinary(c);

	int oneCount = 0;
	for (auto u : bitC)
		if (u == '1')
			oneCount++;

	return oneCount;
}

string toBinary(int n) {
	if (n == 0)
		return "0";

	string result = "";
	while (n >= 1) {
		if (n % 2 != 0)
			result = "1" + result;
		else 
			result = "0" + result;
		n = n / 2;
	}
	return result;
}



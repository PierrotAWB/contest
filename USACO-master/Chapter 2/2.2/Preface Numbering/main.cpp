/* 
ID: andreww7
PROB: preface
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <math.h>

#define N_CHAR 7

using namespace std;
int N;
map<int, string> letterValue;
int letterCount[N_CHAR];

void countLetters();
void initialize();
int intStrip(int N);
string romanNumeral(int N);

int main() {
	ifstream fin("preface.in");
	fin >> N; 
	fin.close();

	initialize();
	countLetters();

	ofstream fout("preface.out");

	if (letterCount[0] != 0) 
		fout << "I " << letterCount[0] << "\n";
	if (letterCount[1] != 0) 
		fout << "V " << letterCount[1] << "\n";
	if (letterCount[2] != 0) 
		fout << "X " << letterCount[2] << "\n";
	if (letterCount[3] != 0) 
		fout << "L " << letterCount[3] << "\n";
	if (letterCount[4] != 0) 
		fout << "C " << letterCount[4] << "\n";
	if (letterCount[5] != 0) 
		fout << "D " << letterCount[5] << "\n";
	if (letterCount[6] != 0) 
		fout << "M " << letterCount[6] << "\n";

	fout.close();
	return 0;
}

void countLetters() {
	for (int i = 1; i <= N; i++) {
		string s = romanNumeral(i);
		for (int j = 0; j < s.length(); j++) {
			switch (s.at(j)) {
				case 'I': letterCount[0]++;
						  break;
				case 'V': letterCount[1]++;
						  break;
				case 'X': letterCount[2]++;
						  break;
				case 'L': letterCount[3]++;
						  break;
				case 'C': letterCount[4]++;
						  break;
				case 'D': letterCount[5]++;
						  break;
				case 'M': letterCount[6]++;
						  break;
				default : break;
			}
		}
	}
}

void initialize() {
	letterValue[1] = "I";
	letterValue[5] = "V";
	letterValue[10] = "X";
	letterValue[50] = "L";
	letterValue[100] = "C";
	letterValue[500] = "D";
	letterValue[1000] = "M";
}

string romanNumeral(int N) {
	string numeral = "";
	while(N >= 1) {
		int t, f; // power of ten, power of five
		t = int(pow(10, floor(log10(N))));
		f = 5 * t; 
		if (N >= f) {
			if (N >= f + 4 * t) {
				numeral += letterValue[t] + letterValue[10 * t];
			} else {
				numeral += letterValue[f];
				for (int i = 0; i < (N - f) / t; i++) {
					numeral += letterValue[t];
				}
			}
		} else {
			if (N >= 4 * t) {
				numeral += letterValue[t] + letterValue[f];
			} else {
				for (int i = 0; i < N / t; i++) {
					numeral += letterValue[t];
				}
			}
		}
		N = N % t;
	}
	return numeral;
}
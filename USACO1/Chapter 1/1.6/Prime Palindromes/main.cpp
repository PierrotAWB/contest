/*
ID: andreww7
TASK: pprime
LANG: C++11
*/

//#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int A, B;
vector<string> palindromes = {};

bool isPrime(int N) { 
	// optimization corner cases
	if (N < 2) return false;
	if (N == 2) return true;
	if (N % 2 == 0) return false; 

	for (int i = 3; i <= pow(N, 0.5); i+=2)
		if (N % i == 0) 
			return false;
	return true;
}

string reverse(string s) { 
	string result = "";
	for (int i = s.length() - 1; i >= 0 ; i--) { 
		result.append(s.substr(i, 1));
	}
	return result;
}

void generatePalindromes(int length) { 
	if (length == 9) return;
	if (length == 1) { 
		if (A <= 5)
			palindromes.push_back("5"); 
		if (A <= 7) 
			palindromes.push_back("7");
		return;
	}

	if (length % 2 == 0) {
		for (int i = pow(10, length / 2 - 1); i < pow(10, length / 2); i++){
			
			string base = to_string(i);
			
			if (base.at(0) == '2' ||
				base.at(0) == '4' ||
				base.at(0) == '5' ||
				base.at(0) == '6' ||
				base.at(0) == '8') continue;
			
			base.append(reverse(base));
			
			if (length == to_string(B).length())
				if (stoi(base) > B) 
					break;

			if (length == to_string(A).length()) 
				if (stoi(base) < A) 
					continue;
			
			palindromes.push_back(base);
			// cout << base << endl;
		}
	} else { 
		for (int i = pow(10, length / 2); i < pow(10, length / 2 + 1); i++) { 

			string base = to_string(i);
			
			if (base.at(0) == '2' ||
				base.at(0) == '4' ||
				base.at(0) == '5' ||
				base.at(0) == '6' ||
				base.at(0) == '8') continue;
			
			base.append(reverse(base.substr(0, base.length() - 1)));
			
			if (length == to_string(B).length())
				if (stoi(base) > B) 
					break;

			if (length == to_string(A).length()) 
				if (stoi(base) < A) 
					continue;

			palindromes.push_back(base);
			// cout << base << endl;
		}
	}
}

void solve() { 
	ofstream fout ("pprime.out");
	for (int i = to_string(A).length(); i <= to_string(B).length(); i++) { 
		generatePalindromes(i);
		for (auto u : palindromes) {
			if (isPrime(stoi(u))) { 
				fout << u << "\n";
			}
		}
		palindromes.erase(palindromes.begin(), palindromes.end());
	}

	fout.close();
}

int main() {
	// auto start = clock();
	ifstream fin ("pprime.in"); 
	fin >> A >> B; 
	fin.close();

	solve();
	// cout << isPrime(5) << " " << isPrime(7) << " " << isPrime(8) << " " << isPrime((int)1e9 + 9) << endl;
	// cout << (clock() - start)/(double) CLOCKS_PER_SEC << endl;
	return 0;
}
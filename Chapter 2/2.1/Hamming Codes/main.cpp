#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std; 

int N, B, D;

// vector<string> generateBitstring(int length);
string toBinary(int n);
int hammingDistance(int a, int b);

int main() { 
	ifstream fin("hamming.in");
	fin >> N >> B >> D; 
	fin.close();

	cout << hammingDistance(1364, 564) << endl;

	// ofstream fout("hamming.in");
	// for (int i = 0; i < N / 10; i++) {
	// 	for (int j = 0; j < 10; j++) {
	// 		cout << codeword[10*i + j] << " ";
	// 	}
	// }
	// for (int i = 10 * (N / 10); i < N; i++) {
	// 	cout << codeword[i] << " ";
	// }
	// fout.close();
	return 0;
}


// vector<string> generateBitstring(int length) {
// 	vector<string> x;
// 	if (length == 1) {
// 		x.push_back("1");
// 		x.push_back("0");
// 		return x;
// 	}

// 	vector<string> y = generateBitstring(length - 1);
// 	for (int i = 0; i < y.size(); i++) {
// 		x.push_back(y[i] + "1");
// 		x.push_back(y[i] + "0");
// 	}
// 	return x; 
// }

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



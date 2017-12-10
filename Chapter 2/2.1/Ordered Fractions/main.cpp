/*
ID: andreww7
TASK: frac1
LANG: C++11
*/

#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std; 

vector<pair<string, double> > value;
int N;

int gcd(int a, int b) {
	if (b == 0)
		return a; 
	return gcd(b, a%b);
}

bool comp(pair<string, double> p, pair<string, double> q) { 
	return p.second < q.second;
}

int main() { 
	ifstream fin("frac1.in");
	fin >> N;
	fin.close();

	// value.push_back({"0/1", 0});

	for (int i = 1; i <= N; i++) { // denom's
		for (int j = 0; j <= i; j++) { 
			if (gcd(i, j) == 1) { 
				value.push_back({to_string(j) + "/" + to_string(i), j / (double) i});
			}
		}
	}

	sort(value.begin(), value.end(), comp);

	ofstream fout("frac1.out");
	for (auto u : value) 
		fout << u.first << "\n";
	fout.close();

	return 0;
}
/*
ID: andreww7
TASK: holstein
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int V, G;  
int minimum[25];
vector<vector<int> > scoop;
set<int> optimalScoopSet;

bool comp(string a, string b);
int countOne(string s);
void determineOptimalScoops(vector<string> v);
vector<string> generateBitstrings(int G);
bool meetsMinimum(int sum[], int length);

int main() { 
	ifstream fin("holstein.in");
	fin >> V; 

	for (int i = 0; i < V; i++){
		fin >> minimum[i];
	}
	fin >> G; 

	for (int i = 0; i < G; i++) { 
		vector<int> currentScoop; 
		for (int i = 0; i < V; i++) { 
			int k; 
			fin >> k; 
			currentScoop.push_back(k);
		}
		scoop.push_back(currentScoop);
	}
	fin.close();

	vector<string> v = generateBitstrings(G);
	sort(v.begin(), v.end(), comp);
	determineOptimalScoops(v);

	ofstream fout("holstein.out");
	fout << optimalScoopSet.size() << " ";
	vector<int> a;
	a.assign(optimalScoopSet.begin(), optimalScoopSet.end());
	for(int i = 0; i < a.size() - 1; i++)
		fout << a[i] << " ";
	fout << a[a.size() - 1] << "\n";
	fout.close();

	return 0;
}

bool comp(string a, string b) {
	// sort primarily by number of ones (increasing), then by decreasing value
	if (countOne(a) != countOne(b))
		return countOne(a) < countOne(b);
	else 
		return a > b;
}

int countOne(string s) {
	int count = 0;
	for (int i = 0; i < s.length(); i++)
		if (s.at(i) == '1') 
			count++;
	return count;
}

void determineOptimalScoops(vector<string> v) {
	// for each bitstring, process
	for (int i = 0; i < v.size(); i++) { 
		string bstring = v[i];
		int sum[25] = {0};
		for (int j = 0; j < G; j++) { 
			if (bstring.at(j) == '1') {
				for (int k = 0; k < V; k++) {
					sum[k] += scoop[j][k];
				}
			}
		}

		if (meetsMinimum(sum, V)){
			for (int j = 0; j < G; j++) {
				if (bstring.at(j) == '1')
					optimalScoopSet.insert(j + 1);
			}
			return;
		}
	}
}

vector<string> generateBitstrings(int G) {
	vector<string> x; 
	if (G == 1) {
		x.push_back("1"); 
		x.push_back("0");
		return x;
	}
	vector<string> y; 
	y = generateBitstrings(G - 1);
	for (auto u : y) {
		x.push_back(u + "1");
		x.push_back(u + "0");
	}
	return x;
}

bool meetsMinimum(int sum[], int length) {
	for (int i = 0; i < length; i++)
		if (sum[i] < minimum[i])
			return false;
	return true;
}



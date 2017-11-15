#include <fstream>
#include <iostream>
#include <set>
#include <math.h>

using namespace std;

// global variables and constants
const int MAX_DIFF = 17;
multiset<int> hill;
int N;

int determineCost(multiset<int> hill) {
	int cost = 0;
	while (*(--hill.end()) - *hill.begin() > MAX_DIFF) {
		int a, b;
		a = *hill.begin();
		b = *(--hill.end());
		int delta = int(ceil((b - a - MAX_DIFF)/(double)2));
		cost += 2 * delta * delta;
		hill.erase(hill.find(a));
		hill.erase(hill.find(b));
		hill.insert(a + delta);
		hill.insert(b - delta);
	}
	return cost;
}

int main() {
	ifstream fin("skidesign.in");
	
	fin >> N;
	
	for (int i = 0; i < N; i++) {
		int k;
		fin >> k;
		hill.insert(k);
	}
	
	for (auto u : hill) {
		cout << u << " ";
	}
	
	ofstream fout("skidesign.out");
	fout << determineCost(hill) << "\n";
}

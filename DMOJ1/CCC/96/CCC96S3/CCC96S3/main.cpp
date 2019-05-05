#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX_N 31

using namespace std; 

int N, n, k;
vector<vector<string> > bitstring;

vector<string> generate(int length, int n_ones) {
	if (n_ones == 0) { 
		sort(bitstring[n-1].begin(), bitstring[n-1].end(), reverse);
		for (auto u : bitstring[n-1])
			cout << u << endl;
		return;
	}

	// add 1's into sub solutions
	generate
}

int main() { 
	cin >> N; 
	for (int i = 0; i < N; i++) { 
		cin >> n >> k; 
		cout << "The bit patterns are\n";
		generate(n, k);
		if (i != N - 1) cout << endl;
		bit.reset();
	}
	return 0;
}
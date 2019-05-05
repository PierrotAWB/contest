#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <vector>

#define watch(x) cout << "CURRENT VALUE: " << x << endl;

using namespace std; 

int N, w[100002], minCow = 0;

int main() {
	ifstream fin("lemonade.in");
	fin >> N;
	for (int i = 0; i < N; i++) {
		fin >> w[i];
	}
	fin.close();

	sort(w, w + N);
	reverse(w, w + N);
	int j = 0; 
	while (w[j] >= j) {
		// cout << w[j] << " " << j << endl;
		minCow++;
		j++;
	}

	ofstream fout("lemonade.out");
	fout << minCow << "\n";
	fout.close();
	
	return 0;
}
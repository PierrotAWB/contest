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

// tree 
vector<pair<int, int> > adj[5001];
bitset<5001> visited;

int N, Q;

int rel(int v, int i) {
	if (v == i) return -1000;
	
	else return rel()
}

int countSuggested(int v, int k) {
	int n_suggested = 0;
	for (int i = 1; i < N; i++) {
		if (rel(v, i) > k)
			n_suggested++;
	}
	return n_suggested;
}

int main() {
	ifstream fin ("mootube.in");
	ofstream fout("mootube.out");
	fin >> N >> Q; 
	for (int i = 0; i < N; i++) {
		int p, q, r; 
		fin >> p >> q >> r; 
		adj[p].push_back({q, r});
		adj[q].push_back({p, r});
	}
	for (int i = 0; i < Q; i++) {
		int v, k;
		fin >> v >> k; 
		fout << countSuggested(v, k) << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}	
/*
 ID: andreww7
 TASK: ariprog
 LANG: C++11
 */

#include <fstream>
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <set>

// #include <ctime>

using namespace std;

int N, M;
vector<pair<int, int> > ariprog = {}; // contains all "pairs" that give the
// valid arithmetic progressions
bitset<500000> bbisquares;
vector<int> vbisquares;

bool cmp(pair<int, int> p, pair<int, int> q) {
	if (p.second != q.second)
		return p.second < q.second;
	return p.first < q.first;
}

void generateBisquares(int M) {
	for (int i = 0; i <= M; i++) {
		for (int j = i; j<= M; j++) {
			bbisquares[i * i + j * j] = true;
			vbisquares.push_back(i * i + j * j);
		}
	}
}

void determineBisquareAP(int k, int difference, int depth) {
	if (depth == 1) { // base case
		ariprog.push_back(make_pair(k - (N - 1) * difference, difference));
	}
	
	// if (N == 21 && k + difference > 125000 || k + difference < 0) cout << k + difference << " " << bbisquares[k + difference] << endl;
	if (bbisquares[k + difference]){
		// if (N == 21 && depth <= 19) cout << k << " " << k + difference << " " << depth << endl;
		determineBisquareAP(k + difference, difference, depth - 1);
	}
}

int main() {

	//auto start = clock();
	//double duration;

	ifstream fin ("ariprog.in");
	fin >> N >> M;
	fin.close();
	
	generateBisquares(M);

	// if (N == 21) cout << "1: OK" << endl;
	set<int> sbisquares(vbisquares.begin(), vbisquares.end());
	vbisquares.assign(sbisquares.begin(), sbisquares.end());

	// if (N == 21) cout << "2: OK" << endl;

	for (int i = 0; i < vbisquares.size(); i++) // first in seq
		for (int j = i + 1; j < vbisquares.size(); j++) // second in seq
			determineBisquareAP(vbisquares[i], vbisquares[j] - vbisquares[i], N);
	
	// if (N == 21) cout << "3: OK" << endl;

	sort(ariprog.begin(), ariprog.end(), cmp);
	
	ofstream fout ("ariprog.out");
	if (ariprog.size())
		for (int i = 0; i < ariprog.size(); i++)
			fout << ariprog[i].first << " " << ariprog[i].second << "\n";
	else fout << "NONE\n";

	//duration = (clock() - start)/ (double) CLOCKS_PER_SEC;
	//cout << duration << endl;
	fout.close();
}

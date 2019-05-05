/*/*
 ID: andreww7
 TASK: milk
 LANG: C++
 */

#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm> // sort

using namespace std;

//pair<int, int> farmer[5001]; // first = price, second = amount
vector<pair<int, int> > farmer;

bool comp(pair<int, int> p, pair<int, int> q) { // p < q?
	return p.first < q.first;
}

// 881208

int main() {
	ifstream fin("milk.in");
	ofstream fout("milk.out");
	
	int M, N;
	fin >> N >> M;
	
	int milkAccumulator = 0; // accumulate until N reached
	int costAccumulator = 0;
	
	for (int i = 0; i < M; i++) { // read in all the milk offers
		int P, A;
		fin >> P >> A;
		farmer.push_back(make_pair(P, A));
	}
	
	sort(farmer.begin(), farmer.end(), comp); // sort into non-decresing order by price

	int i = 0;
	if (M > 0) {
		do {
			if (farmer[i].second <= N - milkAccumulator) {
				milkAccumulator += farmer[i].second;
				costAccumulator += farmer[i].first * farmer[i].second;
			} else {
				int diff = N - milkAccumulator;
				cout << diff;
				milkAccumulator = N; // to stop the while loop
				costAccumulator += farmer[i].first * diff;
			}
			i++;
		} while (N > milkAccumulator && i < M);
	}
	
	fout << costAccumulator << "\n";
	return 0;
}



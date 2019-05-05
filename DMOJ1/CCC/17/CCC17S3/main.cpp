#include <iostream>
#include <algorithm>

using namespace std; 

int N; 
int boardFreq[2001];
int lengthFreq[4001];

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N; 

	for (int i = 0; i < N; i++) { 
		int L; 
		cin >> L;
		boardFreq[L]++; // 1 index
	} 

	// determine the length Freq's 
	// a sum can only be formed in very specific ways

	for (int i = 2; i <= 4000; i++) { // each possible board lenght, determine how many boards can be formed from the wood
		for (int j = 1; j <= i - j; j++) {
			int k = i - j;  
			if (k <= 2000) {
				if (k != j) 
					lengthFreq[i] += min(boardFreq[j], boardFreq[k]);
				else 
					lengthFreq[i] += boardFreq[j] / 2;
			}
		}
	}
	// determine max of lengthFreq
	sort(lengthFreq, lengthFreq + 4001);
	int maxFenceLength = lengthFreq[4000];
	auto count = equal_range(lengthFreq, lengthFreq + 4001, maxFenceLength);
	cout << maxFenceLength << " " << count.second - count.first << "\n";
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> unlucky; 
// stores the number of unlucky numbers less than N at index N.
int nUnlucky[1000001]; 

int main() { 
	int N, K; 
	cin >> K; 
	for (int i = 0; i < K; i++) { 
		int u; 
		cin >> u; 
		unlucky.push_back(u); // store negative value to maintain order.
	}

	sort(unlucky.begin(), unlucky.end());

	int unluckyCount = 0; 
	int targetIndex = 0;
	for (int i = 0; i < 1000001; i++) {
		if (i == unlucky[targetIndex]) {
			unluckyCount++;
			targetIndex++;
		}
		nUnlucky[i] = unluckyCount; 
	}

	cin >> N; 
	for (int i = 0; i < N; i++) { 
		int f; 
		cin >> f; 
		cout << f - nUnlucky[f] << endl;
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <deque>
#include <math.h>
#include <algorithm>

using namespace std;

int N;
vector<int> measurement;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) { 
		int k; 
		cin >> k; 
		measurement.push_back(k);
	}

	// sort the deque and alternate pops
	sort(measurement.begin(), measurement.end());
	vector<int> lowTide;
	vector<int> highTide;

	for (int i = 0; i < ceil(N/(double)2); i++) 
		lowTide.push_back(measurement[i]);
	for (int i = ceil(N/(double)2); i < N; i++)
		highTide.push_back(measurement[i]);

	sort(lowTide.rbegin(), lowTide.rend());
	sort(highTide.begin(), highTide.end());

	if (N % 2 == 0) { 
		for (int i = 0; i < lowTide.size(); i++) { 
			cout << lowTide[i] << " " << highTide[i] << " ";
		}
	} else {
		cout << lowTide[0] << " ";
		for (int i = 0 ; i < highTide.size(); i++) { 
			cout << highTide[i] << " " << lowTide[i + 1] << " ";
		}
	}

	cout << endl;

	return 0;
}
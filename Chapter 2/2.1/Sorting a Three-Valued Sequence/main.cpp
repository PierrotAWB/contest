/*
ID: andreww7
TASK: sort3
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std; 

int N, n_exchange = 0, tally[3];
vector<int> keyValue;

void exchange(int a, int b) { 
	int k = keyValue[a];
	keyValue[a] = keyValue[b];
	keyValue[b] = k;
}

bool beginsCorrectly(int key) { 
	int index = key - 1;
	for (int i = 0; i < tally[index]; i++)
		if (keyValue[i] != 1)
			return false;
	return true;
}

void swapSort() {
	// SORT 1's in 2's places with 2's in 1's places

	int a = 0; // # 2's in 1's position
	int b = 0; // # 1's in 2's position

	for (int i = 0; i < tally[0]; i++)
		if (keyValue[i] == 2) a++;
	for (int i = tally[0]; i < tally[0] + tally[1]; i++) 
		if (keyValue[i] == 1) b++;

	for (int i = 0; i < min(a, b); i++) { 
		for (int j = 0; j < tally[0]; j++) { 
			if (keyValue[j] == 2) {
				for (int k = tally[0]; k < tally[0] + tally[1]; k++) { 
					if (keyValue[k] == 1) { 
						exchange(j, k);
					}
				}
			}
		}
	}

	n_exchange += min (a, b);

	// cout << "AFTER 1 & 2 " << n_exchange << endl;
	// for (auto u : keyValue) 
	// 	cout << u << " ";
	// cout << endl;

	// SORT 1's in 3's places with 3's in 1's places

	a = 0; // # 3's in 1's position
	b = 0; // # 1's in 3's position

	for (int i = 0; i < tally[0]; i++)
		if (keyValue[i] == 3) a++;
	for (int i = tally[0] + tally[1]; i < N; i++) 
		if (keyValue[i] == 1) b++;

	for (int i = 0; i < min(a, b); i++) { // number of swaps needed
		for (int j = 0; j < tally[0]; j++) { 
			if (keyValue[j] == 3) {
				for (int k = tally [0] + tally[1]; k < N; k++) { 
					if (keyValue[k] == 1) { 
						exchange(j, k);
					}
				}
			}
		}
	}

	n_exchange += min (a, b);

	// cout << "AFTER 1 & 3 " << n_exchange << endl;
	// for (auto u : keyValue) 
	// 	cout << u << " ";
	// cout << endl;

	// SORT 2's in 3's places with 3's in 2's places

	a = 0; // # 3's in 2's position
	b = 0; // # 2's in 3's position

	for (int i = tally[0]; i < tally[0] + tally[1]; i++)
		if (keyValue[i] == 3) a++;
	for (int i = tally[0] + tally[1]; i < N; i++) 
		if (keyValue[i] == 2) b++;

	for (int i = 0; i < min(a, b); i++) { // number of swaps needed
		for (int j = tally[0]; j < tally[0] + tally[1]; j++) { 
			if (keyValue[j] == 3) {
				for (int k = tally[0] + tally[1]; k < N; k++) { 
					if (keyValue[k] == 2) { 
						exchange(j, k);
					}
				}
			}
		}
	}

	n_exchange += min (a, b);

	//cout << "AFTER 2 & 3 " << n_exchange << endl;
	// for (auto u : keyValue) 
	// 	cout << u << " ";
	// cout << endl;

	// cout << n_exchange << endl;
	// for (auto u : keyValue) cout << u << " "; cout << "\n";

	// SORT the remaining cycles

	for (int i = N - 1; i >= tally[0]; i--) { 
		if (keyValue[i] == 1) { 
			for (int j = 0; j < i; j++) { 
				if (keyValue[j] != 1) { 
					exchange(i, j);
					n_exchange++;
					break;
				}
			}
		}
	}

	// cout << "AFTER THE ONES " << n_exchange << endl;

	for (int i = N - 1; i >= 0; i--) { 
		if (keyValue[i] == 2) { 
			for (int j = tally[0]; j < i; j++) { 
				if (keyValue[j] != 2) { 
					exchange(i, j);
					n_exchange++;
					break;
				}
			}
		}
	}

	// cout << "AFTER EVERYTHING " << n_exchange << endl;

}

int main() { 
	ifstream fin("sort3.in");
	fin >> N;
	for (int i = 0; i < N; i++) { 
		int k; 
		fin >> k; 
		tally[k - 1]++;
		keyValue.push_back(k);
	}
	fin.close();

	// cout << tally[0] << " " << tally[1] << " " << tally[2] << endl;

	// for (auto u : keyValue) cout << u << " "; cout << "\n";

	swapSort();

	// for (auto u : keyValue) cout << u << " "; cout << "\n";

	ofstream fout("sort3.out");
	fout << n_exchange << "\n";
	fout.close();

	return 0;
}

// 1 1 2 2 3 3 3 3 2

// 1 1 2 2 2 3 3 3 3

// 4

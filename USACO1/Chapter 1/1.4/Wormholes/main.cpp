/*
ID: andreww7
TASK: wormhole
LANG: C++11
*/

#include <fstream>
#include <iostream>

#define MAX_N 12

using namespace std; 

int X[MAX_N + 1], Y[MAX_N + 1]; // hold the coordinates
int partner[MAX_N + 1]; // hold partner of wormhole w at index w (0 if unpaired)
int next_on_right[MAX_N + 1];
int N;

bool cycleExists() {
	for (int start = 1; start <= N; start++) { // starting points
		int current = start;
		for (int nSteps = 0; nSteps < N; nSteps++) { // number of 'rounds'
			current = next_on_right[partner[current]];
		}
		if (current != 0) return true;
	}
	return false;
}

int countSolutions() { 
	int i, total = 0;
	for (i = 1; i <= N; i++) // identify the first unpaired wormhole
		if (partner[i] == 0) break;

	if (i > N) {  // everyone is paired
		return cycleExists();
	}

	for (int j = i + 1; j <= N; j++) { 
		if (partner[j] == 0) { // find the next wormhole to be paired
			partner[i] = j; 
			partner[j] = i; 

			total += countSolutions();

			partner[i] = partner[j] = 0;
		}
	}
	return total;
}

int main() { 
	ifstream fin ("wormhole.in");
	fin >> N; 
	for (int i = 1; i <= N; i++)
		fin >> X[i] >> Y[i];
	fin.close();

	// create next on right array
	for (int i = 1; i <= N; i++) { // all wormholes
		for (int j = 1; j <= N; j++) { // all candidates for "next on right"
			if (X[j] > X[i] && Y[i] == Y[j]) { 
				if (next_on_right[i] == 0 || 
					X[j] - X[i] < X[next_on_right[i]] - X[i]) { 
					next_on_right[i] = j;
				}
			}
		}
	}

	ofstream fout ("wormhole.out");
	fout << countSolutions() << "\n";
	fout.close();
}
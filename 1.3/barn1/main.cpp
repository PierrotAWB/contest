/*
ID: andreww7
TASK: barn1
LANG: C++
*/

#include <fstream>
#include <iostream>

using namespace std; 

pair<bool, bool> stall[201]; // hasCow and isCovered

// Find the longest chain of unnecessarily covered stalls,
// find the length of the chain and its start index, 
// and remove that part of the board, effectively splitting it in 2
void splitBoard(int lowerBoundIndex, int upperBoundIndex) { 
		int longestPatch = 0; // tracker of maximum chain of covered empty stalls
		int currentLongestPatch = 0; // temporary tracker w same purpose
		int chainStartIndex; 

		for (int i = lowerBoundIndex; i <= upperBoundIndex; i++) { 
			if (!stall[i].first && stall[i].second) { 
				currentLongestPatch++;
				if (currentLongestPatch > longestPatch) {
					longestPatch = currentLongestPatch;
					chainStartIndex = i - longestPatch + 1;
				}
			} else { 
				currentLongestPatch = 0;
			}
		}

		for (int j = chainStartIndex; j < chainStartIndex + longestPatch; j++) {
			stall[j].second = false; // uncover; remove that part of the board
		}
}

int main() { 

	ifstream fin("barn1.in");
	ofstream fout("barn1.out");

	int M, S, C; 
	fin >> M >> S >> C;

	if (M > C) { 
		fout << C << "\n";
		return 0;
	}

	int upperBoundIndex = 1;
	int lowerBoundIndex = 200;

	for (int i = 0; i < C; i++) { 
		int Ci; 
		fin >> Ci; 

		if (Ci > upperBoundIndex) upperBoundIndex = Ci; 
		if (Ci < lowerBoundIndex) lowerBoundIndex = Ci;

		stall[Ci].first = true; // that stall has a cow
	}

	for (int j = lowerBoundIndex; j <= upperBoundIndex; j++) { 
		stall[j].second = true; // is covered
	}

	// increase "M" by one with optimal solution (Greedy approach)
	for (int k = 2; k <= M; k++) { 
		splitBoard(lowerBoundIndex, upperBoundIndex); 
	}	

	int coveredCounter = 0;
	for (int i = lowerBoundIndex; i <= upperBoundIndex; i++) { 
		if (stall[i].second) {
			coveredCounter++;
		}

	}

	fout << coveredCounter << "\n";
}
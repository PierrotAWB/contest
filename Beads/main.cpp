/*
ID: andreww7
PROG: beads
LANG: C++
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// index is the bead to the immediate right of the cut
int calculateScore(char bead[], int index, int size) { 
	// one bead from the left and right are guaranteed
	int score = 2; 
	int rightMarker; // the index at which the right-search stops

	int k;
	if (index <= size - 2) k = index + 1; // moving index
	else k = 0; 

	// search right: 
	if (bead[index] == 'r' || bead[index] == 'b') { 
		char key = bead[index]; // comparison key
		while (bead[k] == key || bead[k] == 'w') { 
			score++;
			k++;
			if (k == size) k = 0;
			if (k == index) return size;
		}
		rightMarker = k;
	} else { 

		int withRed = 0, withBlue = 0;

		while (bead[k] == 'b' || bead[k] == 'w') { 
			withBlue++; 
			k++;
			if (k == size) k = 0;
			if (k == index) return size;
		}

		if (index <= size - 2) k = index + 1; // moving index
		else k = 0; 

		while (bead[k] == 'r' || bead[k] == 'w') { 
			withRed++; 
			k++;
			if (k == size) k = 0;
			if (k == index) return size;
		}

		score += max(withRed, withBlue); 
		rightMarker = max(withRed, withBlue) % size;
	}

	// search left: 
	if (index == 0) k = size - 1; 
	else k = index - 1;

	int j; 
	if (k == 0) j = size - 1; 
	else j = k - 1;

	if (bead[k] == 'r' || bead[k] == 'b') { 

		char key = bead[k]; // comparison key
		while (bead[j] == key || bead[j] == 'w') {
			score++; 
			j--;
			if (j == -1) j = size - 1;
			// ensure that the left-search does not overlap with the right-search
			if (j <= rightMarker && j >= index) break;
		}

	} else { 

		int withRed = 0, withBlue = 0;

		while (bead[j] == 'b' || bead[j] == 'w') { 
			withBlue++; 
			j--;
			if (j == -1) j = size - 1;
			if (j <= rightMarker && j >= index) break;
		}

		if (k == 0) j = size - 1; 
		else j = k - 1;

		while (bead[j] == 'r' || bead[j] == 'w') { 
			withRed++; 
			j--;
			if (j == -1) j = size - 1;
			if (j <= rightMarker && j >= index) break;
		}

		score += max(withRed, withBlue); 
	}

	return score;
}

int main() {
	ofstream fout ("beads.out");
	ifstream fin ("beads.in");
	int N; string necklace;
	
	fin >> N;
	char bead[N];

	// variable to store the maximum 
	// number of beads collected in the visited starting indices
	int maxCollection = 0; 

	for (int i = 0; i < N; i++) {
		fin >> bead[i];
	}
	
	for (int i = 0; i < N; i++) {
		//fout << i << ": " <<  calculateScore(bead, i, N); 
		if (calculateScore(bead, i, N) > maxCollection) { 
			maxCollection = calculateScore(bead, i, N);
			//fout << "*";
		}
		//fout << "\n";
	}

	fout << maxCollection << "\n"; 
    return 0;
}

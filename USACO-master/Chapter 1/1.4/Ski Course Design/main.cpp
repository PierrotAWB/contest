/* 
ID: andreww7
LANG: C++11
TASK: skidesign
*/

// this method attempts to greedily cut out the pairs that exceed 17 in difference

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> hill; 

int main() {
	ifstream fin ("skidesign.in");
	ofstream fout ("skidesign.out");
	int N; 
	fin >> N; 
	for (int i = 0; i < N; i++) { 
		int k; 
		fin >> k; 
		hill.push_back(k);
	}
	sort(hill.begin(), hill.end());

	for (int i = 0; i < N; i++) { 
		fout << hill[i] << " ";
	}

	fout << endl << endl;

	int cost = 0; 
	while (hill[N-1] - hill[0] > 17) { // until it is officially a ski camp
		int difference = hill[N-1] - hill[0], adjustment;

		if (difference % 2 != 0) { 
			adjustment = (difference - 17) / 2; 
			hill[0] += adjustment; 
			hill[N-1] -= adjustment;
			cost += 2 * adjustment * adjustment;
		} else { 
			adjustment = (difference - 17) / 2; 
			// does it matter where the smaller one gets added?
			hill[0] += adjustment + 1; 
			hill[N-1] -= adjustment;
			cost += adjustment * adjustment + (adjustment + 1) * (adjustment + 1);
		}	
		sort(hill.begin(), hill.end());
		for (int i = 0; i < N; i++) { 
			fout << hill[i] << " ";
		}

		fout << ":" << difference << " " << adjustment << " " << hill[0] << " " << hill[N-1] << " " << cost;
		fout << endl << endl; 

		
	}
	fout << cost << "\n";
	return 0;
}
/*
ID: andreww7
PROG: milk2
LANG: C++
*/

#include <bitset>
// #include <iostream>
#include <fstream>

using namespace std; 

bitset<1000001> isCowMilked; 
// a bitset of seconds where if a cow is milked during the ith second,
// the value at the ith index is 1.

int main() { 

	ofstream fout ("milk2.out");
	ifstream fin ("milk2.in");

	int N, endTime = 0, startTime = 1000001;
	fin >> N;

	for (int i = 0; i < N; i++) { 
		int start, end; 
		fin >> start >> end; 

		if (end > endTime) endTime = end; 
		if (start < startTime) startTime = start;

		for (int j = start; j < end; j++) { 
			if (!isCowMilked[j]) { // will execute if no milking
				isCowMilked[j] = isCowMilked[j] | 1;
			}
		}
	}

	int maxNoMilk = 0, maxMilk = 0, temp = 0;

	int key = isCowMilked[startTime];

	for (int i = startTime; i < endTime; i++) { 
		if (isCowMilked[i] == key) { 
			temp += 1;
		} else { // change state
			if (key == 0) { 
				if (temp > maxNoMilk) maxNoMilk = temp; 
			} else { 
				if (temp > maxMilk) maxMilk = temp;
			}
			key = isCowMilked[i];
			// reset to one because the differing
			// second must be included
			temp = 1;
		}
	}

	if (!key && temp > maxNoMilk) maxNoMilk += temp;
	else if (key && temp > maxMilk) maxMilk += temp;

	fout << maxMilk << " " << maxNoMilk << "\n";
	return 0;
}
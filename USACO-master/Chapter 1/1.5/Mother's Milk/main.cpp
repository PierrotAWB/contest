/* 
ID: andreww7
TASK: milk3
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <set>
#include <string>

#define N_BUCKETS 3

using namespace std; 

set<int> possibleC;
set<string> pastState;

int capacity[N_BUCKETS + 1];
int bucket[N_BUCKETS + 1];

// DEBUG
int K;

string concatenate(int A, int B, int C) { 
	string s = "";
	s.append(to_string(A));
	s.append(" ");
	s.append(to_string(B));
	s.append(" ");
	s.append(to_string(C));
	s.append(" ");
	return s;
}

void simulate() { 
	if (pastState.count(concatenate(bucket[1], bucket[2], bucket[3])) > 0) return;
	pastState.insert(concatenate(bucket[1], bucket[2], bucket[3]));

	// if (bucket[3] == 14) {
	// 	cout << bucket[1] << " " << bucket[2] << " " << bucket[3] << endl;
	// 	K = 15;
	// }

	// if (K > 0) { 
	// 	cout << bucket[1] << " " << bucket[2] << " " << bucket[3] << endl;
	// 	cout << K << endl;
	// 	K--;
	// }

	if (bucket[1] == 0) { 
		possibleC.insert(bucket[3]);
	}

	// find the next bucket in which milk can be poured
	for (int i = 1; i <= N_BUCKETS; i++) { 
		if (bucket[i] < capacity[i]) { 
			
			// find the next bucket that can pour; pour it into the previous bucket
			for (int j = 1; j <= N_BUCKETS; j++) { 
				if (j != i && bucket[j] > 0) {  // if j can pour, pour

					int m = bucket[i], n = bucket[j];

					if (bucket[j] + bucket[i] <= capacity[i]) { 
						bucket[i] = bucket[i] + bucket[j];
						bucket[j] = 0;
					} else { 
						int diff = capacity[i] - bucket[i];
						bucket[i] = capacity[i];
						bucket[j] -= diff;
					}

					simulate(); 

					bucket[i] = m; 
					bucket[j] = n;

				}
			}
		}
	}
}

int main() { 
	ifstream fin ("milk3.in");
	fin >> capacity[1] >> capacity[2] >> capacity[3]; 
	fin.close();

	bucket[3] = capacity[3]; // C starts off filled

	simulate();

	ofstream fout ("milk3.out");
	auto it = possibleC.begin(); 
	fout << *it;
	for(it++; it != possibleC.end(); it++) { 
		fout << " " << *it; 
	}
	fout << "\n";
	fout.close();
}
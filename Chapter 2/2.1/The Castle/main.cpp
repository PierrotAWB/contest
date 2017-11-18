/* 
ID: andreww7
TASK: castle
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// castle stores adjacency lists of a module at its coordinates
map<pair<int, int>, vector<pair<int, int> > > adj; 
int N, M; 

void developFloorPlan(int i, int j, string wallScheme) { 
	// open to south
	if ((int) wallScheme.at(0) == 48 && i != N) { 
		adj[{i, j}].push_back({i + 1, j});
	}	
	// open to east
	if ((int) wallScheme.at(1) == 48 && j != M) { 
		adj[{i, j}].push_back({i, j + 1});
	}	
	// open to north
	if ((int) wallScheme.at(2) == 48 && i != 1) { 
		adj[{i, j}].push_back({i - 1, j});
	}	
	// open to west
	if ((int) wallScheme.at(3) == 48 && j != 1) { 
		adj[{i, j}].push_back({i, j - 1});
	}	
}

string toBin(int k) { 
	string result = ""; 
	while (k >= 1) { 
		if (k % 2 == 0) { 
			result = "0" + result;
		} else { 
			result = "1" + result;
		}

		k /= 2; 
	}

	// pad with zeros
	if (result.length() < 4) { 
		int n_zeros = 4 - result.length();
		for (int i = 0; i < n_zeros; i++) { 
			result = "0" + result;
		}
	}

	return result;
}

int main() {
	ifstream fin ("castle.in");
	fin >> M >> N; 
	for (int i = 1; i <= N; i++ ) { 
		for (int j = 1; j <= M; j++) { 
			int wall; 
			fin >> wall; 
			developFloorPlan(i, j, toBin(wall));
		}
	}


	// GRAPH OUTPUT

	// for (int i = 1; i <= N; i++) { 
	// 	for (int j = 1; j <= M; j++) { 
	// 		cout << i << " " << j << ": ";
	// 		for (auto u : adj[{i, j}]) { 
	// 			cout << u.first << " " << u.second << endl;
	// 		}
	// 		cout << endl;
	// 	}
	// }


	return 0;
}

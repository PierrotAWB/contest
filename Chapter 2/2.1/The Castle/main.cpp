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
#include <set>

using namespace std;

// castle stores adjacency lists of a module at its coordinates
map<pair<int, int>, vector<pair<int, int> > > adj; 
map<pair<int, int>, int> roomNumber; // maps room coordinates to integer components
map<pair<int, int>, int> potential;
map<int, int> roomSize;
int N, M; 
int currentRoom = 1;

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

void floodFill(int i, int j) {
	if (roomNumber[{i, j}] == 0){ // not visited; DFS all neighbours
		roomNumber[{i, j}] = currentRoom; 
		for (auto u : adj[{i, j}]) { 
			floodFill(u.first, u.second);
		}
	}
}

void determinePotential(int i, int j){ 
	if (adj[{i, j}].size() == 4) 
		potential[{i, j}] = 0;
	else { 
		int maxPotential = 0;
		// check above
		if (i >= 2)
			if (roomNumber[{i - 1, j}] != roomNumber[{i, j}]) 
				if (roomSize[roomNumber[{i - 1, j}]] + roomSize[roomNumber[{i, j}]] > maxPotential)
					maxPotential = roomSize[roomNumber[{i - 1, j}]] + roomSize[roomNumber[{i, j}]];

		// check right
		if (j <= M - 1)
			if (roomNumber[{i, j + 1}] != roomNumber[{i, j}]) 
				if (roomSize[roomNumber[{i, j + 1}]] + roomSize[roomNumber[{i, j}]] > maxPotential)
					maxPotential = roomSize[roomNumber[{i, j + 1}]] + roomSize[roomNumber[{i, j}]];

		// check below
		if (i <= N - 1)
			if (roomNumber[{i + 1, j}] != roomNumber[{i, j}]) 
				if (roomSize[roomNumber[{i + 1, j}]] + roomSize[roomNumber[{i, j}]] > maxPotential)
					maxPotential = roomSize[roomNumber[{i + 1, j}]] + roomSize[roomNumber[{i, j}]];

		// check left
		if (j >= 2)
			if (roomNumber[{i, j - 1}] != roomNumber[{i, j}]) 
				if (roomSize[roomNumber[{i, j - 1}]] + roomSize[roomNumber[{i, j}]] > maxPotential)
					maxPotential = roomSize[roomNumber[{i, j - 1}]] + roomSize[roomNumber[{i, j}]];
		potential[{i, j}] = maxPotential;
	}
}

int main() {
	ifstream fin ("castle.in");
	fin >> M >> N; 

	// encode the castle as a graph
	for (int i = 1; i <= N; i++ ) { 
		for (int j = 1; j <= M; j++) { 
			int wall; 
			fin >> wall; 
			developFloorPlan(i, j, toBin(wall));
		}
	}
	fin.close();

	// GRAPH OUTPUT

	// for (int i = 1; i <= N; i++) { 
	// 	for (int j = 1; j <= M; j++) { 
	// 		cout << i << " " << j << ": ";
	// 		for (auto u : adj[{i, j}]) { 
	// 			cout << u.first << " " << u.second << "; ";
	// 		}
	// 		cout << "\n";
	// 	}
	// }

	// categorize the modules into categories
	for (int i = 1; i <= N; i++) { 
		for (int j = 1; j <= M; j++) { 
			floodFill(i, j);
			currentRoom++;
		}
	}

	// determine the number of rooms and the largest room
	set<int> uniqueRooms;
	multiset<int> roomMSet;
	for (int i = 1; i <= N; i++) { 
		for (int j = 1; j <= M; j++) { 
			uniqueRooms.insert(roomNumber[{i, j}]);
			roomMSet.insert(roomNumber[{i, j}]);
		}
	}	

	int largestRoom = 0;

	for (int i = 1; i <= N; i++) { 
		for (int j = 1; j <= M; j++) { 
			roomSize[roomNumber[{i, j}]] = roomMSet.count(roomNumber[{i, j}]);
			if (roomMSet.count(roomNumber[{i, j}]) > largestRoom)
				largestRoom = roomMSet.count(roomNumber[{i, j}]);
		}
	}

	// find the greatest potential
	for (int i = 1; i <= N; i++) { 
		for (int j = 1; j <= M; j++) { 
			determinePotential(i, j);
		}
	}

	int currentPotential = 0, x, y; 
	for (int j = 1; j <= M; j++) { // prioritize west, then south
		for (int i = N; i >= 1; i--) { 
			if (potential[{i, j}] > currentPotential) {
				currentPotential = potential[{i, j}];
				x = i;
				y = j;
			}
		}
	}
	
	// determine whether the removed wall is N or E
	string wall; 
	int EPot, NPot;
	// compare potentials
	if (y == M) 
		EPot = 0;
	else if (roomNumber[{x, y}] != roomNumber[{x, y + 1}])
		EPot = roomSize[roomNumber[{x, y}]] + roomSize[roomNumber[{x, y + 1}]]; 
	else 
		EPot = 0;


	if (x == 1) 
		NPot = 0;
	else if (roomNumber[{x, y}] != roomNumber[{x - 1, y}])
		NPot = roomSize[roomNumber[{x, y}]] + roomSize[roomNumber[{x - 1, y}]]; 
	else 
		NPot = 0;

	wall = (EPot > NPot) ? "E" : "N";



	// output section
	ofstream fout("castle.out");
	fout << uniqueRooms.size() << "\n";
	fout << largestRoom << "\n";
	fout << currentPotential << "\n";
	fout << x << " " << y << " " << wall << "\n";
	fout.close();

	return 0;
}

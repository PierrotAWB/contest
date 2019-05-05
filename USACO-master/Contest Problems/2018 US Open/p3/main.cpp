#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <vector>

#define watch(x) cout << "CURRENT VALUE: " << x << endl;

using namespace std; 

int N, roomID = 1;
int grid[253][253];
int room[253][253];
bool visited[253][253];

void DFS(int i, int j, int id){
	// should check visited only if it belongs to the current region
	
	// up
	if (grid[i - 1][j] == id) {
		visited[i - 1][j] = true;
		room[i - 1][j] = roomID;
		DFS(i - 1, j, id);
	}

	// down
	if (grid[i + 1][j] == id) {
		visited[i + 1][j] = true;
		room[i + 1][j] = roomID;
		DFS(i + 1, j, id);
	}

	// right
	if (grid[i][j + 1] == id) {
		visited[i][j + 1] = true;
		room[i][j + 1] = roomID;
		DFS(i, j + 1, id);
	}

	// left
	if (grid[i][j - 1] == id) {
		visited[i][j - 1] = true;
		room[i][j - 1] = roomID;
		DFS(i, j - 1, id);
	}
}

int main() {
	ifstream fin("multimoo.in");
	fin >> N; 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			fin >> grid[i][j];
		}
	}
	fin.close();

	// init padding
	for (int i = 0; i <= N; i++) {
		grid[0][i] = -1;
		grid[i][0] = -1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][j]) {
				room[i][j] = roomID;
				DFS(i, j, grid[i][j]);
				roomID++;
			}
		}
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			cout << room[i][j] << " ";
		}
		cout << endl;
	}
	
	ofstream fout("multimoo.out");
	fout.close();
	return 0;
}
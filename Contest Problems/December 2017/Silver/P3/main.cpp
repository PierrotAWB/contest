#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <set>

using namespace std; 

int N; 
int succ[100001];
bitset<1000001> visited;

int occupied = 0;

void unvisit(int node, int counter) {
	if (counter == 0)
		return;
	else {
		// if (node == 5) cout << "OK" << endl;
		visited[node] = 0;
		unvisit(succ[node], counter - 1);
	}
}

void DFS(int s, int x, int stepCount) {
	if (stepCount > N) {
		unvisit(succ[x], stepCount); // unvisit the nodes that were stepped through, they could still belong to other cycles
		// cout << "UNVISITING" << endl;
		return;
	}
	if (s == x && stepCount > 0) {
		// if (s == 5) cout << "OK" << endl;
		// every node just visited is in the cycle
		occupied += stepCount; 
		return;
	}
	if (visited[s] == 0) {
		// if (s == 5) cout << "X: " << x << " " << stepCount + 1 << endl;
		visited[s] = 1;
		DFS(succ[s], x, stepCount + 1);
	}
	// also no cycle
	else {
		unvisit(succ[x], stepCount);
		// cout << "UNVISITING" << endl;
		return;
	}
}

int main() {
	ifstream fin("shuffle.in");
	fin >> N; 
	// store the successor graph
	for (int i = 1; i <= N; i++) { 
		fin >> succ[i];
	}
	fin.close();

	for (int i = 1; i <= N; i++){ 
		DFS(i, i, 0);
	}

	ofstream fout ("shuffle.out");
	fout << occupied << "\n";
	fout.close();

	return 0;
}
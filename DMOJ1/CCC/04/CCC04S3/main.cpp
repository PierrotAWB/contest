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

int value[11][10];
string spreadsheet[11][10];
bool visited[11][10];

vector<int> adj[91];

int N;

int convertToID(string cell) {
	int row = int(cell.at(0)) - 64;
	int col = stoi(cell.substr(1, 1));
	return (row - 1) * 9 + col;
}

pair<int, int> convertToPos(int ID) {
	int i = 1, j; 
	while (ID > 9) {
		ID -= 9; 
		i++;
	}
	j = ID;
	return {i, j};
}

bool isNumber(string s) {
	for (auto u : s) 
		if (!isdigit(u))
			return false;
	if (s == "-1")
		return false;
	return true;
}

void addDependencies(int i, int j, string exp) {
	for (i = 0; i < exp.length(); i+=3) {
		adj[9*(i - 1) + j].push_back(convertToID(exp.substr(i, 2)));
	}
}

bool allAreKnown(int i, int j){ // if one of the dependencies of cell is not known, return false
	for (auto u : adj[9*(i - 1) + j]) {
		pair<int, int> coord = convertToPos(u);
		if (!isNumber(spreadsheet[coord.first][coord.second]))
			return false;
	}
	return true;
}

int compute(int i, int j) {// determine the expression's value
	int sum = 0;
	for (auto u : adj[9*(i - 1) + j]) {
		pair<int, int> coord = convertToPos(u);
		sum += stoi(spreadsheet[coord.first][coord.second]);
	}
	return sum;
}

void unlink(int i, int j) {	// all nodes referencing i, j are undefined
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 9; j++) {
			if (find(adj[9*(i - 1) + j].begin(), adj[9*(i - 1) + j].end(), 9*(i - 1) + j) == 
			    adj[9*(i - 1) + j].end()) {
				value[i][j] = -1;
				spreadsheet[i][j] = -1;
			}
		}
	}
}

void evaluate(int i, int j){ // process the expression; update the spreadsheet
	if (visited[i][j]) {
		value[i][j] = -1;
		spreadsheet[i][j] = -1;
		unlink(i, j);
		return;
	}
	visited[i][j] = true;
	if (allAreKnown(i, j)) {
		cout << i << " " << j << " OK " << endl;
		value[i][j] = compute(i, j);
		spreadsheet[i][j] = to_string(value[i][j]);
	} else { // follow the tracks
		for (auto u : adj[9*(i - 1) + j]) {
			pair<int, int> a = convertToPos(u);
			evaluate(a.first, a.second);
		}
	}
}

void clearVisited(){
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 9; j++) {
			visited[i][j] = false;
		}
	}
}

int main() {
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 9; j++) {
			string exp;
			cin >> exp;

			spreadsheet[i][j] = exp;
			if (!isNumber(exp)) {
				addDependencies(i, j, exp);
			}
		}
	}

	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 9; j++) {
			if (isNumber(spreadsheet[i][j])) {
				value[i][j] = stoi(spreadsheet[i][j]);
			} else { // is an expression to be evaluated
				clearVisited();
				evaluate(i, j);
			}
		}
	}

	cout << endl;

	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 9; j++){
			if (value[i][j] >= 0)
				cout << value[i][j] << " ";
			else 
				cout << "* ";
		}
		cout << "\n";
	}
	return 0;
}
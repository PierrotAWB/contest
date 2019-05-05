#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <queue>
#include <string>

using namespace std; 

const int s = 80; 
const int INF = 1000000;

int matrix[s][s];
vector<pair<int, int> > adj[s*s];
bool processed[s*s];
int dist[s*s];
priority_queue<pair<int, int> > q;

int main() {
	ifstream fin("p083_matrix.txt"); 
		// row
		for (int i = 0; i < s; i++) {
			string line;
			getline(fin, line);
			int k = 0;
			// col
			for (int j = 0; j < s; j++) {
				// string index
				string num = "";
				for (; k < line.length(); k++) {
					if (line.at(k) != ',') {
						num += to_string(line.at(k) - 48);
					} else {
						k++;
						break;
					}
				}
				matrix[i][j] = stoi(num);
			}
		}
	fin.close();

	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			/// NOTE: this is far simpler if 
			/// implemented using a try and catch clause.
			/// The case checking here is crazy.


			// top row
			if (i == 0) {
				// left column
				if (j == 0) {
					adj[i*s + j].push_back({(i+1)*s+j, matrix[i+1][j]});
					adj[i*s + j].push_back({i*s+j+1, matrix[i][j+1]});
				} 
				// right column
				else if (j == s - 1) {
					adj[i*s + j].push_back({(i+1)*s+j, matrix[i+1][j]});
					adj[i*s + j].push_back({i*s+j-1, matrix[i][j-1]});
				} 
				// anything in the middle
				else {
					adj[i*s + j].push_back({(i+1)*s+j, matrix[i+1][j]});
					adj[i*s + j].push_back({i*s+j+1, matrix[i][j+1]});
					adj[i*s + j].push_back({i*s+j-1, matrix[i][j-1]});
				}
			} 
			// bottom row
			else if (i == s - 1) {
				// left column
				if (j == 0) {
					adj[i*s + j].push_back({(i-1)*s+j, matrix[i-1][j]});
					adj[i*s + j].push_back({i*s+j+1, matrix[i][j+1]});
				} 
				// right column
				else if (j == s - 1) {
					adj[i*s + j].push_back({(i-1)*s+j, matrix[i-1][j]});
					adj[i*s + j].push_back({i*s+j-1, matrix[i][j-1]});
				} 
				// anything in the middle
				else {
					adj[i*s + j].push_back({(i-1)*s+j, matrix[i-1][j]});
					adj[i*s + j].push_back({i*s+j+1, matrix[i][j+1]});
					adj[i*s + j].push_back({i*s+j-1, matrix[i][j-1]});
				}
			}
			// left column
			else if (j == 0) {
				adj[i*s + j].push_back({(i-1)*s+j, matrix[i-1][j]});
				adj[i*s + j].push_back({(i+1)*s+j, matrix[i+1][j]});
				adj[i*s + j].push_back({i*s+j+1, matrix[i][j+1]});
			}
			// right column
			else if (j == s - 1) {
				adj[i*s + j].push_back({(i-1)*s+j, matrix[i-1][j]});
				adj[i*s + j].push_back({(i+1)*s+j, matrix[i+1][j]});
				adj[i*s + j].push_back({i*s+j-1, matrix[i][j-1]});
			}
			// centre element
			else {
				adj[i*s + j].push_back({(i-1)*s+j, matrix[i-1][j]});
				adj[i*s + j].push_back({(i+1)*s+j, matrix[i+1][j]});
				adj[i*s + j].push_back({i*s+j-1, matrix[i][j-1]});
				adj[i*s + j].push_back({i*s+j+1, matrix[i][j+1]});
			}
		}
	}

	// for (int i = 0; i < s*s; i++) {
	// 	cout << i << ": " << endl;
	// 	for (auto u : adj[i]) {
	// 		cout << u.first << " " << u.second << ", ";
	// 	}
	// 	cout << endl;
	// }

	for (int i = 0; i < s*s; i++)
		dist[i] = INF;
	dist[0] = 0;
	q.push({0,0});
	while (!q.empty()) {
		// set a to the current node
		int a = q.top().second; 
		q.pop();
		if (processed[a]) continue;
		processed[a] = true;
		for (auto u : adj[a]) {
			// b is the destination node, w is the weight of
			// edge a--b
			int b = u.first, w = u.second; 
			if (dist[b] > dist[a] + w) {
				dist[b] = dist[a] + w;
				q.push({-dist[b], b});
			}
		}
	}
	cout << dist[s*s-1] + matrix[0][0] << endl;
	return 0;
}
#include <iostream>

using namespace std; 

bool visited[21][21];

void cutOutCorner(int x, int y, int w, int h) { // cut out a w by h corner w x and y as upper left
	for (int i = x; i < x + h; i++) { 
		for (int j = y; j < y + w; j++) { 
			visited[i][j] = true; 
		}
	}
}

void initGrid(int W, int H, int w, int h) { 
	cutOutCorner(1, 1, w, h); 
	cutOutCorner(1, W - w + 1, w, h);
	cutOutCorner(H - h + 1, 1, w, h); 
	cutOutCorner(H - h + 1, W - w + 1, w, h);

	// top and left edge set to visited
	for (int i = 0; i < 21; i++) { 
		visited[0][i] = true; 
		visited[i][0] = true;
	}

	// // right 'bar' set to visited
	for (int i = 0; i < 21; i++) { // rows
		for (int j = W + 1; j < 21; j++) { // cols 
			visited[i][j] = true;
		}
	}

	// bottom 'bar' set to visited
	for (int i = H + 1; i < 21; i++) { // rows
		for (int j = 0; j < 21; j++) { // cols
			visited[i][j] = true;
		}
	}

	// for (int i = 0; i < 21; i++) { 
	// 	for (int j = 0; j < 21; j++) { 
	// 		cout << visited[i][j] << " "; 
	// 	}
	// 	cout << "\n";
	// }
}

int main() { 
	int W, H, w, h, nsteps; 
	cin >> W >> H >> w >> h >> nsteps;

	initGrid(W, H, w, h);

	pair<int, int> p = make_pair(1, w + 1);

	for (int i = 0; i < nsteps; i++) { 
		if (p.second > W / 2) { 
			if (!visited[p.first][p.second + 1]) { // right is allowed
				visited[p.first][p.second] = true; 
				p.second++;
			} else if (!visited[p.first + 1][p.second]) { // down is allowed
				visited[p.first][p.second] = true; 
				p.first++;
			} else if (!visited[p.first][p.second - 1]) { // left is allowed
				visited[p.first][p.second] = true; 
				p.second--;
			} else if (!visited[p.first - 1][p.second]) {  // up is allowed
				visited[p.first][p.second] = true;
				p.first--;
			} else { 
			}
		} else { 
			if (!visited[p.first][p.second - 1]) { // left is allowed
				visited[p.first][p.second] = true; 
				p.second--;
			} else if (!visited[p.first - 1][p.second]) {  // up is allowed
				visited[p.first][p.second] = true;
				p.first--;
			} else if (!visited[p.first][p.second + 1]) { // right is allowed
				visited[p.first][p.second] = true; 
				p.second++;
			} else if (!visited[p.first + 1][p.second]) { // down is allowed
				visited[p.first][p.second] = true; 
				p.first++;
			} else { 
			}
		}
		//cout << p.first << " " << p.second << endl;
	}

	cout << p.second << endl << p.first << endl;
	return 0;
}
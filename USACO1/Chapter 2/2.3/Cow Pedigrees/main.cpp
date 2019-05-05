/*
ID: andreww7
PROB: nocows
LANG: C++11
*/

#include <array>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;

int d[101][201];
bool v[101][201];

// Compute the number of trees with n_nodes, and height of "height" exactly
int num_trees(int n_nodes, int height) {
	if (n_nodes % 2 == 0) return 0;
	if (v[height][n_nodes]) return d[height][n_nodes];

	if ((n_nodes == 1 && height == 1) || (n_nodes == 3 && height == 2)) {
		v[height][n_nodes] = true;
		return d[height][n_nodes] = 1;
	}
	if (n_nodes < 2 * height - 1 || n_nodes > pow(2, height) - 1) {
		v[height][n_nodes] = true;
		return d[height][n_nodes] = 0;
	}

	int res = 0; 
	for (int i = 1; i <= n_nodes - 1 - i; ++i) {
		for (int j = ceil(log2(i + 1)); j <= height - 1; ++j) {
			for (int k = (j == height - 1) ? ceil(log2(n_nodes - i)) : height - 1; k <= height - 1; ++k) {
				if (i == n_nodes - 1 - i)
					res = (res + num_trees(i, j) * num_trees(n_nodes - 1 - i, k)) % 9901;
				else 
					res = (res + 2*(num_trees(i, j) * num_trees(n_nodes - 1 - i, k))) % 9901;
			}	
		}		
	}

	d[height][n_nodes] = res;
	v[height][n_nodes] = true;
	return res;
}

int main() {
	int N, H;
	ifstream fin("nocows.in");
	fin >> N >> H;
	fin.close();

	ofstream fout("nocows.out");
	fout << num_trees(N, H) << "\n";
	fout.close();
	return 0;
}
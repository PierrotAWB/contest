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

int N;
int table[101][101];
int rotation[101][101];

void rotate(int N){
	int temp[101][101];
	for (int j = 1; j <= N; j++) {
		for (int k = 1; k <= N; k++){
			temp[k][N - j + 1] = rotation[j][k];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			rotation[i][j] = temp[i][j];
		}
	}
}

bool isValid(int N){ // check if rotation in current state is valid

	// check down rows
	for (int i = 1; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			if (rotation[i][j] <= rotation[i][j - 1]) return false;
		}
	}

	// check down cols
	for (int i = 1; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			if (rotation[j][i] <= rotation[j-1][i]) return false;
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	cin >> N; 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> table[i][j];
			rotation[i][j] = table[i][j];
		}
	}

	for (int i = 0; i <= 3; i++) {
		rotate(N);
		if (isValid(N)){
			for (int j = 1; j <= N; j++) {
				for (int k = 1; k <= N; k++){
					cout << rotation[j][k] << " ";
				}
				cout << "\n";
			}
			break;
		}
	}
	return 0;
}
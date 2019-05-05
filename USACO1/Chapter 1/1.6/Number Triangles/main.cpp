/* 
ID: andreww7
TASK: numtri
LANG: C++11
*/

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int R; 
vector<vector<int> > pyramid; 

void calculateMaxPathSum(){ 
	for (int i = pyramid.size() - 1; i > 0; i--) {
		for (int j = 0; j < pyramid[i - 1].size(); j++) {
			pyramid[i - 1][j] += max(pyramid[i][j], pyramid[i][j + 1]);
		}
	}
}

int main() { 
	ifstream fin("numtri.in");
	fin >> R; 
	for (int i = 1; i <= R; i++) { 
		vector<int> row;
		for (int j = 0; j < i; j++) { 
			int k; 
			fin >> k; 
			row.push_back(k);
		}
		pyramid.push_back(row);
	}
	fin.close();
	calculateMaxPathSum();

	ofstream fout("numtri.out");
	fout << pyramid[0][0] << "\n";
	fout.close();
	return 0;
}
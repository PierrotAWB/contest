#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std; 

int N;
int shuffleTemplate[100];

vector<int> cow;
vector<vector<int> > config;

vector<int> shuffle(vector<int> v) { 
	vector<int> shuffled; 
	for (int i = 0; i < N; i++) { 
		shuffled.push_back(v[shuffleTemplate[i] - 1]);
	}
	return shuffled;
}

int main(){
	ifstream fin("shuffle.in");
	fin >> N;
	for (int i = 0; i < N; i++) { 
		fin >> shuffleTemplate[i];
	}
	for (int i = 1; i <= N; i++) { 
		int k; 
		fin >> k; 
		cow.push_back(k);
	}
	fin.close();

	config.push_back(cow);
	for (int i = 0; i < 3; i++) {
		config.push_back(shuffle(config[i]));
	}

	// for (int i = 0; i <= 3; i++) 
	// 	for (auto u : config[i]) 
	// 		cout << u << " ";
	// 	cout << endl;


	ofstream fout("shuffle.out");
	for (auto u : config[3]) {
		fout << u << "\n";
	}
	fout.close();
	return 0;
}
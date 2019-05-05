#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std; 

int N;
vector<int> shuffleTemplate;

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
		int k; 
		fin >> k;
		shuffleTemplate.push_back(k);
	}
	for (int i = 1; i <= N; i++) { 
		cow.push_back(i);
	}
	fin.close();

	config.push_back(cow);
	for (int i = 0; i < N; i++) {
		config.push_back(shuffle(config[i]));
	}

	// for (int i = 0; i <= 3; i++) 
	// 	for (auto u : config[i]) 
	// 		cout << u << " ";
	// 	cout << endl;

	int occupied = config[(int)config.size() - 1].size();

	ofstream fout("shuffle.out");
	cout << occupied << "\n";
	fout.close();
	return 0;
}
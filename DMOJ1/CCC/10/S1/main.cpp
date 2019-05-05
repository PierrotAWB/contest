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

struct computer {
	string name;
	int R, S, D;
	int score() {
		return 2*R + 3*S + D;
	}
};

bool comp(computer a, computer b) {
	if (a.score() != b.score()){
		return a.score() < b.score();
	} 
	// sort in REVERSE ORDER BY NAME
	return a.name > b.name;
}

vector<computer> computerList;
int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N; 
	if (N == 0) {
		return 0;
	}

	for (int i = 0; i < N; i++) {
		computer Computer;
		cin >> Computer.name >> Computer.R >> Computer.S >> Computer.D;
		computerList.push_back(Computer);
	}

	sort(computerList.begin(), computerList.end(), comp);
	reverse(computerList.begin(), computerList.end());

	if (computerList.size() > 1) cout << computerList[0].name << "\n" << computerList[1].name << "\n";
	else cout << computerList[0].name << "\n";
	return 0;
}
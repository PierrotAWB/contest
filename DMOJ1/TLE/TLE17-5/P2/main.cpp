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
struct planet{
	int id; 
	int x;
};

int N, D;
vector<planet> solarSystem;

int main() {
	ios::sync_with_stdio(0);
	cin.tie();
	cin >> N >> D; 
	for (int i = 1; i <= N; i++) {
		int xi;
		cin >> xi;
		planet Planet;
		Planet.id = i; 
		Planet.x = xi;
		solarSystem.push_back(Planet);
	}

	return 0;
}
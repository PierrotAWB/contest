/*
ID: andreww7
PROB: wormhole
LANG: C++11
*/

#include <algorithm>
#include <fstream>
#include <set>
#include <vector>

#include <iostream>

using namespace std; 

// global variables

int N;
vector<pair<int, int> > coordinate; // input coordinates
vector<vector<pair<int, int> > > pairing;

// function declarations
bool coordcomp(pair<int, int> p1, pair<int, int> p2);
void generatePairings(set<int> s, vector<pair<int, int> > v, int index);
void initPairings();
// outer vector contains all ~ sqrt(N!) pairings 

int main() 
{ 
	ifstream fin("wormhole.in"); 
	fin >> N; 

	for (int i = 0; i < N; i++) 
	{ 
		int x, y; 
		fin >> x >> y; 
		coordinate.push_back(make_pair(x, y));
	}

	sort (coordinate.begin(), coordinate.end(), coordcomp);
	initPairings();

	for (int i = 0; i < pairing.size(); i++) { 
		for (int j = 0; j < pairing[i].size(); j++) { 
			cout << pairing[i][j].first << " " << pairing[i][j].second;
		}
		cout << endl;
	}
}

// function definitions
bool coordcomp(pair<int, int> p1, pair<int, int> p2) 
{ 
	if (p1.second != p2.second) return p1.second < p2.second;
	return p1.first < p2.first;
}

void generatePairings(set<int> s, vector<pair<int, int> > v, int index) 
{
	if (s.empty() && index == N / 2) 
	{ 
		pairing.push_back(v); 
		return;
	}

	int a; // first member of pair to be inserted in v
	a = *s.begin();
	
	s.erase(a); 

	for (auto u : s) 
	{ 
		v.push_back(make_pair(a, u));
		s.erase(u);

		generatePairings(s, v, index + 1);

		v.erase(v.begin() + index);
		s.insert(u);
	}
}

void initPairings() 
{ 
 	
	set<int> candidatePool; vector<pair<int, int> > pairList = {};  

	for (int i = 1; i <= N; i++) 
	{ 
		candidatePool.insert(i);
	}

	generatePairings(candidatePool, pairList, 0);
}

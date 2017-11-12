/*
 ID: andreww7
 PROB: wormhole
 LANG: C++11
 */

#include <algorithm>
#include <fstream>
#include <vector>
#include <set>

#include <iostream>

using namespace std;

// global variables

int N;
vector<pair<int, int> > coordinate; // input coordinates
vector<vector<pair<int, int> > > pairing; // vector containing all possible groupings of wormholes

// function declarations
bool coordcomp(pair<int, int> p1, pair<int, int> p2);
void generatePairings(set<int> s, vector<pair<int, int> > v, int index);
bool hasLoop(vector<pair<int, int> >);
void initPairings();
// outer vector contains all ~ sqrt(N!) pairings

int main()
{
	// ifstream fin("wormhole.in");
	cin >> N;
	
	// read in the N pairs of coordinates of the wormholes
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		coordinate.push_back(make_pair(x, y));
	}
	
	sort (coordinate.begin(), coordinate.end(), coordcomp);
	int loopCounter = 0;
	
	// for(auto u : coordinate) {
	// 	cout << u.first << ", " << u.second << endl;
	// }
	
	initPairings();
	
	// for (int i = 0; i < pairing.size(); i++) {
	// 	cout << i << ": ";
	// 	for (int j = 0; j < pairing[i].size(); j++) {
	// 		cout << pairing[i][j].first << " " << pairing[i][j].second << ", ";
	// 	}
	// 	cout << endl;
	// }
	
	// for (int i = 0; i < pairing.size(); i++) {
	// 	cout << i << ": ";
	// 	for (int j = 0; j < pairing[i].size(); j++) {
	// 		cout << "[(" << coordinate[pairing[i][j].first].first << ", " << coordinate[pairing[i][j].first].second << "), (" << coordinate[pairing[i][j].second].first << ", " << coordinate[pairing[i][j].second].second << ")]";
	// 	}
	// 	cout << endl;
	// }
	
	for (int i = 0; i < pairing.size(); i++) {
		if (hasLoop(pairing[i])) loopCounter++;
	}
	
	cout << loopCounter << "\n";
}

// function decinitions

// sort by y primarily and x secondarily
bool coordcomp(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.second != p2.second) return p1.second < p2.second;
	return p1.first < p2.first;
}

void generatePairings(set<int> s, vector<pair<int, int> > v, int index)
{
	if (index == N / 2)
	{
		pairing.push_back(v);
		return;
	}
	int a, b; //pair to be inserted in v
	a = *s.begin();
	s.erase(s.begin());
	
	for (set<int>::iterator it = s.begin(); it != s.end();)
	{
		b = *it;
		v.push_back(make_pair(a, b));
		// increase iterator here (before erasure) so that
		// there is neither undecined behaviour
		// nor iterator invalidation (took about 2 hours of
		// debugging and stack overflow to figure this one out)
		it++;
		s.erase(b);
		generatePairings(s, v, index + 1);
		
		if (s.empty()) return;
		v.erase(v.begin() + index);
		s.insert(b);
	}
}

bool hasLoop(vector<pair<int, int> > grouping) {
	for (int i = 0; i < 2 * grouping.size(); i++) {
		// each of these 2 (N/2) wormholes could be the start of a loop
		vector<int> visited = {};
		pair<int, int> startPoint = coordinate[i];
		
		// find the first positively-collinear wormhole to startpoint
		for (int j = 0; j < coordinate.size(); j++) {
			if (j != i/2 && coordinate[j].second == startPoint.second) {
				if (find(visited.begin(), visited.end(), j) != visited.end()) return true;
				visited.push_back(j);
				startPoint = coordinate[j];
			} else {
				;
			}
		}
	}
	return false;
}

// create the wormhole indices and put them in pairlist to generate the list of pairs
void initPairings()
{
	set<int> candidatePool = {}; vector<pair<int, int> > pairList = {};
	
	for (int i = 0; i < N; i++)
	{
		candidatePool.insert(i);
	}
	
	generatePairings(candidatePool, pairList, 0);
}


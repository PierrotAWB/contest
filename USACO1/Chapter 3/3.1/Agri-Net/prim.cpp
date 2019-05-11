/*
ID: andreww7
PROG: agrinet
LANG: C++
*/

// Implements Prim's algorithm for finding a minimum spanning tree.

#include <algorithm>
#include <array>
#include <bitset>
#include <cstdio>
#include <deque>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map> 
#include <math.h>
#include <queue>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>

#define INF 10000001 /** greater than max possible dist b/w farms */

using namespace std;

ifstream fin("agrinet.in");
ofstream fout("agrinet.out");

/** dist[j] is the distance from j to the working tree */
int dist[101];

/** inTree[i] is true if node i is currently in the tree */
bool inTree[101];

/** adj contains pairs of the form (b, w), where b is a node and w a weight. */
vector<pair<int, int> > adj[101];

int N;

int main()
{
    fin >> N;

	for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				int w; 
				fin >> w;
				if (w != 0) adj[i].push_back(make_pair(j, w));
			}
	}

	for (int i = 0; i < N; ++i) {
		dist[i] = (i == 0) ? 0 : INF;
	}

	/** q stores pairs of the form (-d, x) where d is the distance to the tree
	 * from node x */
	priority_queue<pair<int, int> > q;
	q.push({0, 0});
	int treeSize = 1, treeCost = 0;

	for (auto u : adj[0]) {
		dist[u.first] = u.second;
	}

	while (treeSize < N + 1) {
		// find node with least distance to the tree
		while (inTree[q.top().second]) q.pop();
		int a = q.top().second;
		q.pop();

		// add edge source to MST
		++treeSize;
		treeCost += dist[a];
		inTree[a] = true;

		// update distance after node i added	
		for (auto u : adj[a]) {
			int b = u.first; 
			if (inTree[b]) continue;
			int w = u.second;
			if (dist[b] > w) {
				dist[b] = w;
			}
			q.push(make_pair(-dist[b], b));
		}
	}	

	fout << treeCost << "\n";
    return 0;
}

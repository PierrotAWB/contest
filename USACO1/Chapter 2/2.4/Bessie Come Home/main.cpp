/*
ID: andreww7
PROG: comehome
LANG: C++11
*/

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

#define INF 30000

using namespace std;

FILE *fin = fopen("comehome.in", "r");
FILE *fout = fopen("comehome.out", "w");

// vectors of form (b, w) where b is a node, and w is a weight
vector<pair<int, int> > adj[53];

// 1-26: a-z, 27-52: A-Z
int dist[53];
bool processed[53];

int convert(char c) {
	if (c >= 97) return int(c - '`');
	return int(c - '&');
}

int main()
{
	int P;
	fscanf(fin, "%d ", &P);
	for (int i = 0; i < P; ++i) {
		char a, b;
		int d;	
		fscanf(fin, "%c %c %d ", &a, &b, &d);
		// cout << a << " " << b << " "<< d << endl;
		adj[convert(a)].push_back(make_pair(convert(b), d));
		adj[convert(b)].push_back(make_pair(convert(a), d));
	}
	
	// Dijkstra implemented using the negative values of the weights
	// to cater to C++'s built-in priority_queue with top equal to its MAXIMUM value (not minimum).
	for (int i = 1; i <= 52; ++i) dist[i] = INF;
	priority_queue<pair<int, int> > q;
	dist[52] = 0;
	q.push({0, 52});
	while (!q.empty()) {
		int a = q.top().second;
		q.pop();
		if (processed[a]) continue;
		processed[a] = true;
		for (auto u : adj[a]) {
			int b = u.first;
			int d = u.second;
			if (dist[a]+d < dist[b]) {
				dist[b] = dist[a]+d;	
				q.push({-dist[b], b});
			}
		}
	}

	int ansCow, ansL = INF;
	for (int i = 27; i <= 51; ++i) {
		if (dist[i] < ansL) {
			ansL = dist[i];
			ansCow = i;
		}
	}

	fprintf(fout, "%c %d\n", char(ansCow + int('&')), ansL);
    return 0;
}

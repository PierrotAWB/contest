/*
ID: andreww7
PROG: cowtour
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
#include <set>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>

#define INF 150000

using namespace std;

FILE *fin = fopen("cowtour.in", "r");
FILE *fout = fopen("cowtour.out", "w");

struct Point {
	int x, y;
};

int N; 
double dist[151][151];
double diam[151];
Point pasture[151];

double distance(Point p, Point q) {
	return pow(pow(p.x - q.x, 2) + pow(p.y - q.y, 2), 0.5);
} 

int main()
{
	fscanf(fin, "%d", &N);	

	for (int i = 1; i <= N; ++i) {
		Point p;
		int px, py;
		fscanf(fin, "%d %d\n", &px, &py);
		p.x = px; 
		p.y = py;
		pasture[i] = p;
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			char t;
			fscanf(fin, "%c ", &t);
			if (i == j) dist[i][j] = 0;
			else if (t == '1') dist[i][j] = distance(pasture[i], pasture[j]);
			else dist[i][j] = INF;
		}
	}

	// Floyd-Warshall
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	/** Populate the diam array */
	/** Note that we compute it only ONCE; and that we do so before we
	 * test edges to add in */

	bool visited[151] = {0};
	for (int i = 1; i <= N; ++i) {
			if (visited[i]) 
				continue;
			set<int> connected;
			queue<int> q; 

			q.push(i);
			while(!q.empty()) {
				int t = q.front();
				q.pop();
				if (visited[t]) continue;
				visited[t] = true;
				for (int j = 1; j <= N; ++j) {
					if (dist[t][j] != INF && dist[t][j] != 0) {
						connected.insert(j);
						q.push(j);
					}
				}
			}

			double currentDiameter = 0;
			for (auto u : connected) {
				for (auto v : connected) {
					currentDiameter = max(currentDiameter, dist[u][v]);
				}
			}

			for (auto u : connected) {
				diam[u] = currentDiameter;
			}
	}

	double diameter = INF;

	for (int i = 1; i <= N; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			if (dist[i][j] != INF) continue;
			// Find the longest (non-infinite) distances to pasture i and pasture j
			// When they are joined, their edge is the ONLY one which connects the two groups of pastures.
			double l1 = 0, l2 = 0;
			for (int k = 1; k <= N; ++k) {
				if (dist[i][k] != INF && dist[i][k] > l1) l1 = dist[i][k];
				if (dist[j][k] != INF && dist[j][k] > l2) l2 = dist[j][k];
			}

			/** longest distance within pasture[i]'s group + that of pasture[j]'s group, + 
			 * the distance between pasture[i] and pasture[j] */
			double d1 = l1 + distance(pasture[i], pasture[j]) + l2; 

			/** the maximum of the diameter of pasture[i]'s group and that of pasture[j] */
			double d2 = INF;
			d2 = max(diam[i], diam[j]);
			
			diameter = min(diameter, max(d1, d2));
		}
	}

	fprintf(fout, "%0.6f\n", diameter); 
    return 0;
}

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
Point pasture[152];

double distance(Point p, Point q) {
	return pow(pow(p.x - q.x, 2) + pow(p.y - q.y, 2), 0.5);
} 

int main()
{
	fscanf(fin, "%d", &N);	
	// Greedy approach: we shall assume the best edge to add is the 
	// one which adds the least length.
	int b1 = 0, b2 = 151;
	
	Point p1, p2;
	p1.x = 0; p2.x = INF;
	p1.y = 0; p2.y = INF;
	pasture[b1] = p1; pasture[b2] = p2;

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
			else {
				dist[i][j] = INF;
				if (distance(pasture[i], pasture[j]) < distance(pasture[b1], pasture[b2])) {
					b1 = i;
					b2 = j;
				}
			}
		}
	}

	// Floyd-Warshall
	// for (int k = 1; k <= N; ++k) {
	// 	for (int i = 1; i <= N; ++i) {
	// 		for (int j = 1; j <= N; ++j) {
	// 			dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	// 		}
	// 	}
	// }

	double diameter = 0;

	// // TOO INEFFICIENT!
	// for (int i = 1; i <= N; ++i) {
	// 	for (int j = i + 1; j <= N; ++j) {
	// 		// Current edge does not exist; recompute shortest paths with the edge added
	// 		if (dist[i][j] == INF) {
	// 			double tmp[151][151];
	// 			for (int p = 1; p <= N; ++p)
	// 				for (int q = 1; q <= N; ++q) 
	// 					tmp[p][q] = dist[p][q];

	// 			tmp[i][j] = distance(pasture[i], pasture[j]);
	// 			tmp[j][i] = distance(pasture[i], pasture[j]);
	// 			double tmpDiam = 0;	

	// 			for (int k = 1; k <= N; ++k) {
	// 				for (int s = 1; s <= N; ++s) {
	// 					for (int t = 1; t <= N; ++t) {
	// 						tmp[s][t] = min(tmp[s][t], tmp[s][k] + tmp[k][t]);
	// 						if (tmp[s][t] != INF) tmpDiam = max(tmpDiam, tmp[s][t]);
	// 					}
	// 				}
	// 			}

	// 			// We would like to determine the "optimal" edge to add, 
	// 			// where, by "optimal", we mean yielding least graph diameter
	// 			diameter = min(diameter, tmpDiam);
	// 		} 
	// 	}		
	// }
	// cout << b1 << " " << b2 << endl;

	dist[b1][b2] = distance(pasture[b1], pasture[b2]);
	dist[b2][b1] = distance(pasture[b1], pasture[b2]);

	for (int k = 1; k <= N; ++k) {
		for (int s = 1; s <= N; ++s) {
			for (int t = 1; t <= N; ++t) {
				dist[s][t] = min(dist[s][t], dist[s][k] + dist[k][t]);
				if (dist[s][t] != INF) diameter = max(diameter, dist[s][t]);
			}
		}
	}


/** 	Print the adjacency matrix */

	// for (int i = 1; i <= N; ++i) {
	// 		for (int j = 1; j <= N; ++j) {
	// 			if (dist[i][j] == INF) cout << "*      ";
	// 			else cout << dist[i][j] << "      ";
	// 		}
	// 	cout << endl;
	// }

	fprintf(fout, "%0.6f\n", diameter); 
    return 0;
}

/*
ID: andreww7
PROG: cowtour
LANG: C++
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

	// TODO: join disconnected pastures, then resulting diameter


/** 	Print the adjacency matrix */

	// for (int i = 1; i <= N; ++i) {
	// 	for (int j = 1; j <= N; ++j) {
	// 		if (dist[i][j] == INF) cout << "*      ";
	// 		else cout << dist[i][j] << "      ";
	// 	}
	// 	cout << endl;
	// }

	// for (auto u : pasture) cout << u.x << " " << u.y << endl;
	double ans = 5*pow(2, 0.5);
	printf("%0.6f\n", ans); 
    return 0;
}

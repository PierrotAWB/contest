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
double diameter[151];
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

	/** 	Print the adjacency matrix */
	// ofstream fout("cowtour.out");
	// for (int i = 1; i <= N; ++i) {
	// 		for (int j = 1; j <= N; ++j) {
	// 			if (dist[i][j] == INF) fout << "*      ";
	// 			else fout << dist[i][j] << "      ";
	// 		}
	// 	fout << endl;
	// }

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

			// COMPUTING d2 IS FAR TOO SLOW IN THE WORST CASE (the graph is very dense)


			/** the maximum of the diameter of pasture[i]'s group and that of pasture[j] */
			double d2 = INF, dimI = 0, dimJ = 0;

			set<int> connected;
			
			bool visited[151];
			queue<int> q;
			q.push(i);
			while(!q.empty()) {
				int t = q.front();
				q.pop();
				if (visited[t]) continue;
				visited[t] = true;
				for (int k = 1; k <= N; ++k) {
					if (dist[t][k] != INF) {
						connected.insert(k); 
						q.push(k);
					}
				}
			}
			// for (auto u : connected) cout << u << " ";
			vector<int> vc;

			for (auto u : connected) 
				vc.push_back(u);
			
			int l = vc.size();
			
			for (int k = 0; k < l; ++k) {
				for (int m = k + 1; m < l; ++m) {
					dimI = max(dimI, dist[vc[k]][vc[m]]); 
				}
			}

			for (int k = 1; k <= N; ++k) visited[k] = false;
			connected.clear();
			vc.clear();
			q.push(j);
			while(!q.empty()) {
				int t = q.front();
				q.pop();
				if (visited[t]) continue;
				visited[t] = true;
				for (int k = 1; k <= N; ++k) {
					if (dist[t][k] != INF) {
						connected.insert(k); 
						q.push(k);
					}
				}
			}		

			for (auto u : connected) 
				vc.push_back(u);
			
			l = vc.size();

			for (int k = 0; k < l; ++k) {
				for (int m = k + 1; m < l; ++m) {
					dimI = max(dimI, dist[vc[k]][vc[m]]); 
				}
			}

			d2 = max(dimI, dimJ);
			diameter = min(diameter, max(d1, d2));
		}
	}

	fprintf(fout, "%0.6f\n", diameter); 
    return 0;
}

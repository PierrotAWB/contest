/*
ID: andreww7
PROG: stamps
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
#include <set>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

FILE *fin = fopen("stamps.in", "r");
FILE *fout = fopen("stamps.out", "w");

int K, N, M, a[51];
bool b[2000001];

int main()
{
	int maxStamp = -1;
	fscanf(fin, "%d %d ", &K, &N);
	for (int i = 0; i < N; ++i) {
		fscanf(fin, "%d ", &a[i]);
		maxStamp = max(maxStamp, a[i]);
	}
	M = K * maxStamp; // upper bound for answer.

	int d = 1;
	for (int i = 0; i < N; ++i) b[a[i]] = true;
	
	for (d = 2; d <= K; ++d) {
		vector<int> toUpdate;
		for (int i = 1; i < d * maxStamp; ++i) {
			if (b[i] == true) {
				for (int j = 0; j < N; ++j) {
					if (b[i + a[j]] == false) toUpdate.push_back(i + a[j]);
				}	
			}
		}
		for (auto u : toUpdate)
			if (u <= M) 
				b[u] = true;
	}

	int ans = 1;
	while (b[ans]) ++ans;
	fprintf(fout, "%d\n", ans - 1);

    return 0;
}

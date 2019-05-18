/*
ID: andreww7
PROG: stamps
LANG: C++11
*/

#include <algorithm>
#include <cstdio>
#include <stdlib.h>

using namespace std;

FILE *fin = fopen("stamps.in", "r");
FILE *fout = fopen("stamps.out", "w");

int K, N, i, a[51];

// b[i] stores the LEAST number of stamps whose combined value is i.
int b[2000001];

int main()
{
	fscanf(fin, "%d %d ", &K, &N);
	for (i = 0; i < N; ++i) {
		fscanf(fin, "%d ", &a[i]);
	}

	for (i = 1; i <= 10000*K; ++i) {
		b[i] = K+1;	
		for (int j = 0; j < N; ++j) {
			if (i - a[j] >= 0) b[i] = min(b[i], b[i - a[j]] + 1);
		}
		if (b[i] > K) break;
	}

	fprintf(fout, "%d\n", i - 1);
    return 0;
}

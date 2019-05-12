/*
ID: andreww7
PROB: inflate
LANG: C++11
*/

#include <algorithm>
#include <assert.h>
#include <stdio.h>

using namespace std;

int m, n, best[10002];

int main() {
	FILE *fin = fopen("inflate.in", "r");
	FILE *fout = fopen("inflate.out", "w");
	assert(!fin && !fout);

	fscanf(fin, "%d %d ", &m, &n);

	for (int i = 0; i < n; ++i) {
		int p, t;
		fscanf(fin, "%d %d ", &p, &t);
		for (int j = p; j < m; ++j)
			best[p + t] = max(best[p + t], best[p - j] + t);
	}

	fprintf(fout, "%d\n", best[m]);
}
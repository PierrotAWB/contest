/*
ID: andreww7
PROG: humble 
LANG: C++11
*/
#include <stdio.h>

#define MAX_N 100000
#define MAX_PRIME 100

int hum[MAX_N + 1], pindex[MAX_PRIME + 1], p[MAX_PRIME + 1];

int main() {
	FILE* fin = fopen("humble.in", "r");
	FILE* fout = fopen("humble.out", "w");

	int n_prime, N, nhum = 0, minPrime = 0x7FFFFFFF;

	fscanf(fin, "%d %d ", &n_prime, &N); 

	for (int i = 0; i < n_prime; ++i) {
		fscanf(fin, "%d ", &p[i]);
		if (p[i] < minPrime) minPrime = p[i];
		pindex[i] = 0;
	}

	hum[0] = 1;

	while (nhum <= N) {
		int min = 0x7FFFFFFF;

		/** The use of "double" is to combat overflow issue */
		for (int i = 0; i < n_prime; ++i)
			while ((double) hum[pindex[i]] * p[i] <= (double) hum[nhum]) 
				pindex[i]++;

		for (int i = 0; i < n_prime; ++i) 
			if ((double) hum[pindex[i]] * p[i] < min)
				min = hum[pindex[i]] * p[i];
		
		hum[++nhum] = min;
	}

	fprintf(fout, "%d\n", hum[N]);
	return 0;
}
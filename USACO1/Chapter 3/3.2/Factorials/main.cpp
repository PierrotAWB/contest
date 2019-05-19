/*
ID: andreww7
PROG: fact4
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

using namespace std;

FILE *fin = fopen("fact4.in", "r");
FILE *fout = fopen("fact4.out", "w");

int N; 

int main()
{
	fscanf(fin, "%d ", &N);
	int n_five = 0, p = 1;
	while (N >= pow(5, p)) {
		n_five += (int) floor(N / pow(5, p));
		++p;
	}
	int prod = 1, n_two = n_five;
	for (int i = 2; i <= N; ++i) {
		int k = i;
		while (k % 2 == 0 && n_two != 0) {
			k /= 2;
			n_two--;
		}
		while ((k % 5 == 0) && n_five != 0) {
			k /= 5;
			n_five--;
		}
		prod = (prod * k) % 10;
	}
	fprintf(fout, "%d\n", prod);
    return 0;
}

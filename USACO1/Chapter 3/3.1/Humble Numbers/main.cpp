/*
ID: andreww7
PROG: humble 
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

FILE *fin = fopen("humble.in", "r");
FILE *fout = fopen("humble.out", "w");

int K, N;
map<int, int> m;

int main()
{
    fscanf(fin , "%d %d ", &K, &N);
    for (int i = 0; i < K; ++i) {
        int p;
        fscanf(fin , "%d", &p);

    }

	for (auto u : ans) fprintf(fout, "%lld\n", u);
    return 0;
}
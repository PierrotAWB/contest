/*
ID: andreww7
PROG: fracdec
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

#define MAX_L 100000

using namespace std;

FILE *fin = fopen("fracdec.in", "r");
FILE *fout = fopen("fracdec.out", "w");

int N, D;

/** maps t[k] to k */
map<long long, long long> m;

/** stores all intermediate dividends after the decimal point */
long long t[MAX_L];

int main()
{
	fscanf(fin, "%d %d ", &N, &D);	
	/** Compute everything up to and including the decimal point
	 *  with built in integer division */
	string ans = to_string(N/D) + ".";

	t[1] = (long long) 10*(N - D*((int) floor((double) N / (double) D)));
	// cout << ans << endl;
	// cout << t[1] << endl;

	int k = 2;

	while (true) {
		if (m.count(t[k - 1]) != 0) {
			ans += ")";
			break;	
		}

		t[k] = (long long) 10*(t[k - 1] - D*((int) floor((double) t[k - 1] / (double) D)));
		
		if (t[k] == 0) break;
		ans += to_string(t[k] / D); 

		m[t[k]] = k;
		++k;
	}

	cout << ans << endl;
    return 0;
}

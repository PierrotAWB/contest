/*
ID: andreww7
PROG: spin
LANG: C++11
*/

#include <algorithm>
#include <array>
#include <bitset>
#include <cstdio>
#include <cstdarg>
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

FILE *fin = fopen("spin.in", "r");
FILE *fout = fopen("spin.out", "w");

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a%b);
}

// The only use of lcm is in computing the upper bound for
// the number of seconds we have to simulate
int lcm1(int a, int b) {
	return a * b / gcd(a, b);
}

int lcm(int a, int b, int c, int d, int e) {
	return lcm1(a, lcm1(b, lcm1(c, lcm1(d, e))));
}

int main()
{
	int speed[5];
	pair<int, int> wedge[5][5];
	for (int i = 0; i < 5; ++i) {
		int w;
		fscanf(fin, "%d %d ", &speed[i], &w);
		for (int j = 0; j < w; ++j) {
			int a, b;
			fscanf(fin, "%d %d ", &a, &b);
			wedge[i][j] = make_pair(a, b);
		}
	}

    return 0;
}

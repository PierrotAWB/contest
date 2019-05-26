/*
ID: andreww7
PROG: spin
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

FILE *fin = fopen("spin.in", "r");
FILE *fout = fopen("spin.out", "w");

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a%b);
}

int lcm(int a[], int sz) {
	if (sz == 2) {
		return a[0]*a[1] / gcd(a[0], a[1]);
	}
	return lcm()
}

int main()
{
	cout << gcd(140, 20) << endl;
    return 0;
}

/*
ID: andreww7
PROG: maze1
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

using namespace std;

FILE *fin = fopen("maze1.in", "r");
FILE *fout = fopen("maze1.out", "w");

char grid[205][81];

int main()
{
	int W, H, E1r, E1c, E2r, E2c;
	fscanf(fin, "%d %d", &W, &H);
	for (int i = 0; i < 2 * H + 1; ++i)
	{
		for (int j = 0; j < 2 * W + 1; ++j)
		{
			fscanf(fin, "%c", &grid[i][j]);
		}		
	}

	for (int i = 0; i < 2*H+1; ++i) {
		for (int j = 0; j < 2*W+1; ++j){
			cout << grid[i][j];
		}
		cout << "\n";	
	}
    return 0;
}

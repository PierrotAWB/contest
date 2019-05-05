/*
ID: andreww7
PROB: ttwo
LANG: C++11
*/

#include <cstdio>
#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)

// This number was determined on a whim. It works (though originally, I tried 50M).
#define MAX 50000

using namespace std;

struct Player{
	int r, c;
	char d;
};

char grid[12][12];

FILE *fin = fopen("ttwo.in", "r");
FILE *fout = fopen("ttwo.out", "w");

char turn(char d) {
	switch(d) {
		case 'N': return 'E';
		case 'E': return 'S';
		case 'S': return 'W';
		case 'W': return 'N';
	}
}

// Update player p's position. Return the updated struct (rather than mutate a global).
Player update(Player p) {
	Player ret;
	ret.d = p.d;
	ret.c = p.c;
	ret.r = p.r;
	switch(p.d) {
		case 'N': 
			ret.c = p.c;
			if (p.r == 1 || grid[p.r - 1][p.c] == '*')
				ret.d = turn(p.d);
			else 
				ret.r = p.r - 1;
			break;
		case 'E':
			ret.r = p.r;
			if (p.c == 10 || grid[p.r][p.c + 1] == '*')
				ret.d = turn(p.d);
			else
				ret.c = p.c + 1;
			break;
		case 'S':
			ret.c = p.c;
			if (p.r == 10 || grid[p.r+1][p.c] == '*')
				ret.d = turn(p.d);
			else
				ret.r = p.r + 1;
			break;

		case 'W':
			ret.r = p.r;
			if (p.c == 1 || grid[p.r][p.c-1] == '*') 
				ret.d = turn(p.d);
			else
				ret.c = p.c - 1;	
			break;
	}
	return ret;
}

int main() {
	Player F,C;
	for (int i = 1; i <= 10; ++i) {
		for (int j = 1; j <= 10; ++j) {
			fscanf(fin, "%c ", &grid[i][j]);
			if (grid[i][j] == 'F') {
				F.r = i; F.c = j; F.d = 'N';
			} else if (grid[i][j] == 'C') {
				C.r = i; C.c = j; C.d = 'N';
			}	
		}
	}

	// FOR(i,1,11) {
	// 	FOR(j,1,11) {
	// 		cout << grid[i][j];
	// 	}
	// 	cout << endl;
	// }

	int i = 1;
	while (i < MAX) {
		// cout << F.r << " " << F.c << "    " << C.r << " " <<  C.c << "\n";
		F = update(F);
		C = update(C);		
		if (F.r == C.r && F.c == C.c) {
			fprintf(fout, "%d\n", i);
			break;
		}
		++i;
	}
	if (i == MAX) fputs("0\n", fout);
	return 0;
}
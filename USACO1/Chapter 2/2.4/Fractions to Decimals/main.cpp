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

void output(string ans) {
	if (ans.length() <= 76) {
		fprintf(fout, "%s\n", ans.c_str());
		return;
	}
	for (int i = 0; i < ans.length(); i += 76) {
		fprintf(fout, "%s\n", ans.substr(i, min(76, (int) ans.length() - i)).c_str());
	}
}

int main()
{
	fscanf(fin, "%d %d ", &N, &D);	

	/** Compute everything up to and including the decimal point
	 *  with built in integer division */
	string ans = to_string(N/D) + ".";

	if (N % D == 0) {
		ans.append("0");
		fprintf(fout, "%s\n", ans.c_str());
		exit(0);
	}

	t[1] = (long long) 10*(N - D*((int) floor((double) N / (double) D)));
	m[t[1]] = 1;
	ans += to_string(t[1]/D);
	// cout << ans << endl;
	// cout << t[1] << endl;

	int k = 2;

	while (true) {	
		t[k] = (long long) 10*(t[k - 1] - D*((int) floor((double) t[k - 1] / (double) D)));
		if (m.count(t[k]) != 0) {
			ans += ")";
			break;	
		}
		// cout << t[k] << endl;
		
		if (t[k] == 0) break;
		ans += to_string(t[k] / D); 

		m[t[k]] = k;
		++k;
	}

	if (ans[ans.length() - 1] == ')') {
		 ans = ans.substr(0, ans.find('.') + m[t[k]]) + "(" + ans.substr(ans.find('.') + m[t[k]], ans.length() - ans.find('.') + m[t[k]]);
	}

	output(ans);
    return 0;
}

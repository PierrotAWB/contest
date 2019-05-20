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

struct Cow {
	int seniority, duration, arrival;
	bool served;
};

FILE *fin = fopen("convention2.in", "r");
FILE *fout = fopen("convention2.out", "w");

int N, waitTimes[100001];
priority_queue<pair<int, int> > q; 

int main()
{
	fscanf(fin, "%d ", &N);	
	for (int i=0;i<N;++i) {
		int a, t;
		fscanf(fin, "%d %d ", &a, &t);
		q.push(make_pair(-a, t));
	}
	while (!q.empty()) {
		
	}
    return 0;
}

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <stdlib.h>

using namespace std;

FILE *fin = fopen("convention.in", "r");
FILE *fout = fopen("convention.out", "w");

int t[100001];
int N, M, C;

// determine whether it's possible to transport the cows
// using M buses, if we allow ourselves to wait "wait" timesteps
bool pos(int wait) 
{
	int buses = 1;
	int arriveTime = t[0];
	int firstIndex = 0;
	for(int i=0;i<N;++i)
	{
		if (t[i] - arriveTime > wait || i + 1 - firstIndex > C)
		{
			buses++;
			arriveTime = t[i];
			firstIndex = i;
		}
	}
	return buses <= M;
}

int binarySearch(int low, int high) 
{
	// cout << low << " " << high << endl;
	if (low == high) return low;
	if (low + 1 == high) 
	{
		// cout << pos(low) << endl;
		if (pos(low)) return low;
		// cout << high << endl;
		return high;
	}
	int mid = (low + high) / 2;
	if (pos(mid)) return binarySearch(low, mid);
	else return binarySearch(mid, high);
}

int main()
{
	fscanf(fin, "%d %d %d ", &N, &M, &C);
	for (int i = 0; i < N; ++i) fscanf(fin, "%d ", &t[i]);
	sort(t, t+N);
	fprintf(fout, "%d\n", binarySearch(0, 1000000000));
	// cout << pos(3) << endl;
    return 0;
}

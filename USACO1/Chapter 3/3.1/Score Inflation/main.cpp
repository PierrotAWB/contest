/*
ID: andreww7
PROG: inflate
LANG: C++11
*/

#include <algorithm>
#include <array>
#include <assert.h>
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

struct Problem {
    int time, value;
};

FILE *fin = fopen("inflate.in", "r");
FILE *fout = fopen("inflate.out", "w");

int M, N, leastVal = 10001;

/** score[m] is the maximum attainable score after m minutes */
int score[10001]; 
Problem p[10001];

int bestScore(int target) {
    // cout << target << endl;
    int ans = 0;
    if (target < leastVal) {
        score[target] = 0;
        return ans; 
    }
    for (int i = 0; i < N; ++i) {
        if (p[i].time > target) continue;
        else if (score[target - p[i].time] == -1) {
            // recurse
            ans = max(bestScore(target - p[i].time) + p[i].value, ans);
        }
        else ans = max(score[target - p[i].time] + p[i].value, ans);
    }
    score[target] = ans;
    return ans;
}

int main()
{
    assert(fin != NULL && fout != NULL);
    fscanf(fin, "%d %d ", &M, &N);    
    for (int i = 0; i < N; ++i) {
        int points, minutes;
        Problem temp;
        fscanf(fin, "%d %d ", &points, &minutes);
        temp.value = points; 
        temp.time = minutes;
        p[i] = temp;
        leastVal = min(leastVal, minutes);
    } 

    fill_n(score, M + 1, -1);

    fprintf(fout, "%d\n", bestScore(M));
    return 0;
}

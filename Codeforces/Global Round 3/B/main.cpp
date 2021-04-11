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

int n, m, ta, tb, k, bopt = 0;
int ab[200001], bc[200001];

// determine time if you cancel i earliest AB flights, and k - i BC flights
int best(int i) {
    // cout << "----------\ni: " << i << endl;
    int arrival = ab[i] + ta;
    int j = bopt;
    while (j < m) {
        // cout << "j: " << j << endl;
        if (bc[j] >= arrival) {
            bopt = j - 1;
            break;
        }
        j++;
    }
    // cout << "Exited loop, j = " << j << endl;
    if (j + k - i >= m) return -1;
    return bc[j + k - i] + tb;
}


int main()
{
    cin >> n >> m >> ta >> tb >> k;
    for (int i = 0; i < n; ++i) cin >> ab[i];
    for (int i = 0; i < m; ++i) cin >> bc[i];

    if (k >= m || k >= n) {
        cout << -1 << endl;
        return 0;
    }
    
    int bestTime = 0;
    for (int i = k; i >= 0; --i) {
        int B = best(i);
        if (B == -1) {
            cout << -1 << endl;
            return 0;
        }
        else if (B > bestTime) {
            bestTime = B;
        }
    }
    cout << bestTime << endl;
    return 0;
}

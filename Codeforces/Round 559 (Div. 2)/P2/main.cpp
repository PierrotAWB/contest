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

#define INF 1000000001

using namespace std;

int arr[300001];

int main()
{
    int N, k = INF;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; ++i) {
        k = (int) min((double) k, arr[i] / ((double) max(N - i, i - 1)));
    }

    cout << k << endl;
    return 0;
}

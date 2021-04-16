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

int a[500001], n, seq = 0;
map<int, int> nex, e;
queue<int> m[6];

int conv(int targ) {
    switch(targ) {
        case 8: return 0;
        case 15: return 1;
        case 16: return 2;
        case 23: return 3;
        case 42: return 4;
    }
}

void getSeq(int i) {
    // cout << i << "got here ";
    int targ = 8, cur = i;
    while(targ <= 42 && !m[conv(targ)].empty()) {
        if (m[conv(targ)].front() < cur)
            m[conv(targ)].pop();
        else {
            cur = m[conv(targ)].front();
            m[conv(targ)].pop();
            targ = nex[targ];
        }
    }
    if (targ == 43) seq++;
}

int main()
{
    nex[8] = 15; nex[15] = 16; nex[16] = 23; nex[23] = 42; nex[42] = 43;
    e[8] = 0; e[15] = 0; e[16] = 0; e[23] = 0; e[42] = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; 
        if (a[i] != 4) 
            m[conv(a[i])].push(i);
    }
    
    for (int i = 0; i < n; ++i) {
        // cout << i << endl;
        if (a[i] != 4) continue;
        getSeq(i);
    }
    cout << n - seq*6 << endl;
    return 0;
}

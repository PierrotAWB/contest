#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <vector>

#include <stdio.h>

#define watch(x) cout << "CURRENT VALUE: " << x << endl;

using namespace std;

int N;
int village[101];
double neighbourhood[101]; // stores the size of the ith neighbourhood

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> village[i];
    }
    
    double currMin = 2000000001;
    
    sort(village+1, village+N+1);
    
    for (int i = 2; i < N; i++) {
        neighbourhood[i] += (village[i] - village[i-1])/(double)2;
        neighbourhood[i] += (village[i+1] - village[i])/(double)2;
    }
   
    cout.precision(5);
    
    for (int i = 2; i < N; i++) {
        if (neighbourhood[i] < currMin) currMin = neighbourhood[i];
    }
    
    printf("%.1f\n", currMin);
    
    return 0;
}

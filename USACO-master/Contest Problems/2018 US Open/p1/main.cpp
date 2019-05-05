#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <vector>

#define watch(x) cout << "CURRENT VALUE: " << x << endl;

using namespace std;

int N, moo = 0, A[100002], B[100002], maxDist = -100;
bool visited[100002];


int main() {
    ifstream fin("sort.in");
    fin >> N;
    for (int i = 0; i < N; i++) {
        int k;
        fin >> k;
        A[i] = k;
        B[i] = k;
    }
    fin.close();
    
//    cowSort(N);
    sort(B, B + N);
    for (int i = 0; i < N; i++) {
        int dist;
        for (int j = 0; j <= i; j++) {
            if (B[j] == A[i]) {
                if (!visited[j]){
                    visited[j] = true;
                    dist = i - j + 1;
                    if (dist > maxDist) {
                        maxDist = dist;
                    }
                    break;
                } else continue;
            }
        }
    }
    
    
    ofstream fout("sort.out");
    fout << maxDist << "\n";
    fout.close();
    // cout << maxDist << "\n";
    return 0;
}


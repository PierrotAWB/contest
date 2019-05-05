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

int structure[101][101];

using namespace std;

void purge() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            structure[i][j] = 0;
        }
    }
}

bool isGroup(int arr[][101], int x) {
    bool hasIdentity = false, inverse = true, associative = true;
    int identity;
    
    // identity
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= x; j++) {
            if (arr[i][j] != j) break; // not in this row
            if (j == x and arr[i][j] == j) {
                hasIdentity = true; // at least going one way
                identity = i;
            }
        }
        if (hasIdentity) break;
    }
    
    if (!hasIdentity) return false;
    
    for (int i = 1; i <= x; i++) {
        if (arr[identity][i] != i) {
            hasIdentity = false;
            break;
        }
    }
    
    if (!hasIdentity) return false;
    
    // inverse
    for (int i = 1; i <= x; i++) {
        bool inverseFound = false;
        for (int j = 1; j <= x; j++) {
            if (arr[i][j] == identity) {
                // reverse operation is also identity, continue; otherwise stop
                if (arr[j][i] == identity) inverseFound = true;
                else {
                    inverseFound = false;
                    break;
                }
            }
        }
        inverse &= inverseFound;
        if (!inverse) {
            break;
        }
    }
    if (!inverse) return false;
    
    // associativity
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= x; j++) {
            for (int k = 1; k <= x; k++) {
                if (arr[i][arr[j][k]] != arr[arr[i][j]][k]) {
                    associative = false;
                    break;
                }
            }
        }
    }
    if (!associative) {
        return false;
    }
    return true;
}

int main() {
    int x;
    while (cin >> x) {
        if (x == 0) break;
        purge();
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= x; j++) {
                cin >> structure[i][j];
            }
        }
        if(isGroup(structure, x)) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}

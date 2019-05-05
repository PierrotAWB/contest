#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int main() {
    int n;
    cin >> n;

    int maxFib;
    int f1 = 1; int f2 = 1; int temp;
    for (int i = 0; i < n; i++){
        maxFib = f1;

        temp = f2;
        f2 = f1 + f2;
        f1 = temp;
    }
    cout << maxFib;
    return 0;
}

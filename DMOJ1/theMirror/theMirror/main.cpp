#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n){
    if (n == 1) {
        return false;
    } else if (n == 2 || n == 3 || n == 5 || n == 7){
        return true;
    }

    if (n % 2 == 0){
        return false;
    }

    for (int i = 3; i <= pow(n, 0.5); i += 2){
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        int primeCounter = 0;
        for (int j = a; j < b; j++) {
            if (isPrime(j)) {
                primeCounter ++;
            }
        }
        cout << primeCounter << endl;
    }
    return 0;
}

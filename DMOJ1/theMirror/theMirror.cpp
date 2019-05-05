#include <iostream>

using namespace std

bool isPrime(int n){
  if (n == 2 || n == 3) {
    return true;
  }

  for (int i = 2; i < n ** 0.5 + 1; i += 2) {
      if (n % i == 0) {
        return false;
      }
  }

  return true;
}

int main() {
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int a, b, primeCounter;
    cin >> a >> b;
    for (int j = a; j < b; j ++) {
      if (isPrime(j)) {
        primeCounter ++;
      }
    }
    cout << primeCounter;
  }

  return 0;
}

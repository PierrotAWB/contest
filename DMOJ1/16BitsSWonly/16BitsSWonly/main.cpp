#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        long long A, B, P;
        cin >> A >> B >> P;
        if (A * B == P) {
            cout << "POSSIBLE DOUBLE SIGMA" << endl;
        } else {
            cout << "16 BIT S/W ONLY" << endl;
        }

    }
}

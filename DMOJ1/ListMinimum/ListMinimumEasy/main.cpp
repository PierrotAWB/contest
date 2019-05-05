#include <iostream>
#include <algorithm>

using namespace std;

int numArray[100000];
int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i ++ ) {
        cin >> numArray[i];
    }

    sort(numArray, numArray + N);
    for (int i = 0; i < N; i ++) {
        cout << numArray[i]<< endl;
    }
}

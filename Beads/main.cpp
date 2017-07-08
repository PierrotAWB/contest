#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int collection(int N, string necklace) { // given an N and a necklace, find max collection
    int maxCollection = 0; // record keeper
    for (int i = 0; i < N; i++) { // i is the starting index (immediately "right" of the cut
        int numBeads = 1; // the starting bead will always be collected
        vector<int> visitedIndices; // container for visited indices

        /// count right first
        if (necklace.at(i) != 'w') {
            const char token = necklace.at(i);

            int j;

            if (i < N - 1) j = i + 1;
            else j = 0;

            while (necklace.at(j) == token && !(visitedIndices.count(visitedIndices.begin(), visitedIndices.end(), j))){
                if (j = i) {
                    return N;
                }
                if (j != N - 1) {
                    numBeads++;
                    j++;
                } else {
                    j = 0;
                }
                visitedIndices.pushback(j);
            }
        }

        if (numBeads > maxCollection) { // new max found; reassign to record keeper
            maxCollection = numBeads;
        }
    }
}

int main() {
    int N; string necklace;
    cin >> N >> necklace;
    cout << collection(N, necklace);
    return 0;
}

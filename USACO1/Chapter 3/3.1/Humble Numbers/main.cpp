/*
ID: andreww7
PROG: humble 
LANG: C++11
*/

#include <cstdio>
#include <stdlib.h>
#include <set>

using namespace std;

FILE *fin = fopen("humble.in", "r");
FILE *fout = fopen("humble.out", "w");

int K, N, num[101];
set<int> s;

int main()
{
    fscanf(fin , "%d %d ", &K, &N);
    for (int i = 0; i < K; ++i) {
        fscanf(fin , "%d", &num[i]);
        s.insert(num[i]);
    }   
    // Essentially, we maintain a set of size N, replacing the last element
    // until we can no more.
    for (int i = 0; i < K; ++i) {
        auto it = s.begin();
        while (1) {
            int t = (*it)*num[i];
            if (t < 0) break;
            if (s.size() > N) {
                s.erase(--s.end());
                if (t > *(--s.end())) break;
            }
            s.insert(t);
            ++it;
        }
    }
    fprintf(fout, "%d\n", *(--s.end()));
}
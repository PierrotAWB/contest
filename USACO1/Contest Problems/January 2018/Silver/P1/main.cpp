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

struct cow{
    int start;
    int end;
};

int uniqueTime[100002];
vector<cow> guard;
int N;

bool byStart(cow a, cow b) {
    if (a.start != b.start)
        return a.start < b.start;
    else
        return a.end < b.end;
}

bool byEnd(cow a, cow b) {
    return a.end > b.end; // sort in reverse order
}

int main() {
    ifstream fin("lifeguards.in");
    fin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        fin >> a >> b;
        cow Cow;
        Cow.start = a;
        Cow.end = b;
        guard.push_back(Cow);
    }
    fin.close();
    
    sort(guard.begin(), guard.end(), byStart);
    
    // find the cow with the least unique time and fire him.
    for (int i = 0; i < N; i++) {
        uniqueTime[i] = guard[i].end - guard[i].start;
        if (uniqueTime[i] < 0) abort();
    }
    for (int i = 0; i < N - 1; i++) {
        if (guard[i].end > guard[i + 1].start) {
            uniqueTime[i] -= guard[i].end - guard[i + 1].start;
            if (uniqueTime[i] < 0) uniqueTime[i] = 0;
            uniqueTime[i + 1] -= guard[i].end - guard[i + 1].start;
            if (uniqueTime[i + 1] < 0) uniqueTime[i + 1] = 0;
        }
    }
    int min = 1000000001, index;
    for (int i = 0; i < N; i++) {
        if (uniqueTime[i] < min && uniqueTime[i] >= 0) {
            min = uniqueTime[i];
            index = i;
        }
    }
    
    // calculate the total time covered without the cow with number "index"
    // since all endpoints are distinct, we will add the times from right to left
    sort(guard.begin(), guard.end(), byEnd);
    int totalTime;
    if (index == N - 1) totalTime = guard[N - 2].end - guard[N - 2].start;
    else totalTime = guard[N - 1].end - guard[N - 1].start;

    for (int i = 1;; i++) {
        if (i == index) continue;
        if (i == N - 1) {
            totalTime += uniqueTime[i];
            break;
        }
        if (guard[i - 1].start < guard[i].start) {
            if (guard[i - 1].end > guard[i].start) {
                totalTime += guard[i - 1].start - guard[i].start;
            } else {
                totalTime += guard[i].end - guard[i].start;
            }
        }
    } 

    ofstream fout("lifeguards.out");
    fout << totalTime << "\n";
    fout.close();
    return 0;
}

#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <vector>
#include <queue>

#define watch(x) cout << "CURRENT VALUE: " << x << endl;

using namespace std;

struct cell{
    int r;
    int c;
};

int N, M;
char factory[102][102]; // stores the factory data
bool camera[102][102]; // can be seen?
bool visited[102][102];
int numStep[102][102]; // number of steps; fill by BFS

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    
    cell source;
    
    for (int i = 0; i <= M; i++) {
        factory[0][i] = 'W';
        factory[N + 1][i] = 'W';
    }
    
    for (int i = 0; i <= N; i++) {
        factory[i][0] = 'W';
        factory[i][M + 1] = 'W';
    }
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> factory[i][j];
            if (factory[i][j] == 'S') {
                source.r = i; source.c = j;
                numStep[i][j] = 0;
            } else {
                numStep[i][j] = -1; // assume you can't get there.
                if (factory[i][j] == 'C') {
                    // mark camera squares
                }
            }
        }
    }
    
    queue<cell> q;
    q.push(source);
    
    while (!q.empty()) {
        if (visited[q.front().r][q.front().c] == true) {
            q.pop();
            continue;
        }
        visited[q.front().r][q.front().c] = true; // will never be visited again
        //top
        if (factory[q.front().r - 1][q.front().c] != 'W' and factory[q.front().r - 1][q.front().c] != 'C' and visited[q.front().r - 1][q.front().c] == false) {
            numStep[q.front().r - 1][q.front().c] = numStep[q.front().r][q.front().c] + 1;
            cell top;
            top.r = q.front().r - 1; top.c = q.front().c;
            q.push(top);
        }
        // bottom
        if (factory[q.front().r + 1][q.front().c] != 'W' and factory[q.front().r + 1][q.front().c] != 'C' and visited[q.front().r + 1][q.front().c] == false) {
            numStep[q.front().r + 1][q.front().c] = numStep[q.front().r][q.front().c] + 1;
            cell bottom;
            bottom.r = q.front().r + 1; bottom.c = q.front().c;
            q.push(bottom);
        }
        
        // left
        if (factory[q.front().r][q.front().c - 1] != 'W' and factory[q.front().r][q.front().c - 1] != 'C' and visited[q.front().r][q.front().c - 1] == false) {
            numStep[q.front().r][q.front().c - 1] = numStep[q.front().r][q.front().c] + 1;
            cell left;
            left.r = q.front().r; left.c = q.front().c - 1;
            q.push(left);
        }
        //right
        if (factory[q.front().r][q.front().c + 1] != 'W' and factory[q.front().r][q.front().c + 1] != 'C' and visited[q.front().r][q.front().c + 1] == false) {
            numStep[q.front().r][q.front().c + 1] = numStep[q.front().r][q.front().c] + 1;
            cell right;
            right.r = q.front().r; right.c = q.front().c + 1;
            q.push(right);
        }
        q.pop();
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (factory[i][j] == '.') {
                cout << numStep[i][j] << "\n";
            }
        }
    }
    return 0;
}

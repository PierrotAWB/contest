#include <iostream>
#include <algorithm>

using namespace std;

int adjMat[2000][2000] = {0};
bool vis[2000];

void dfs(int s, int B) {
    if (vis[s]) return;
    vis[s] = true;

    if (adjMat[s][B]){
        vis[B] = true;
        return;
    }

    for (auto u: adjMat[s]){
        if (u == 1){ // u is the value of the entry in the matrix
            cout << u << " ";
            cout << distance(adjMat[s], find(adjMat[s], adjMat[s] + 2000, u)) << endl;
            dfs(distance(adjMat[s], find(adjMat[s], adjMat[s] + 2000, u)), B); // u is the index of the non-zero entry in the matrix
        }
    }
}

int main()
{
    int N, M, A, B;

    cin >> N >> M >> A >> B;

    for (int i = 0; i < M; i++){
        int h1, h2;
        cin >> h1 >> h2;
        adjMat[h1][h2] = 1;
        adjMat[h2][h1] = 1;
    }

    for (int i = 1; i < 7; i++){
        for (int j = 1; j < 7; j++){
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }

    dfs(A, B);

    if (vis[B]) {
        cout << "GO SHAHIR!";
    } else {
        cout << "NO SHAHIR!";
    }

    return 0;
}

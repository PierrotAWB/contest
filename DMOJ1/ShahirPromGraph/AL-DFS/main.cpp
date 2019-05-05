#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> adj[2001]; // N is the number of nodes
bool vis[2001];

void dfs(int s, int B){
    if (vis[s] == true) return;
    vis[s] = true;

    if (s == B){ // found the target!
        return;
    }

    for (auto u: adj[s]){
        dfs(u, B);
    }
}

int main()
{
    int N, M, A, B;
    cin >> N >> M >> A >> B;

    for (int i = 0; i < M; i++){
        int h1, h2;
        cin >> h1 >> h2;
        adj[h1].push_back(h2);
        adj[h2].push_back(h1);
    }

    dfs(A, B);

    if (vis[B] == true) {
        cout << "GO SHAHIR!";
    } else {
        cout << "NO SHAHIR!";
    }

    return 0;
}

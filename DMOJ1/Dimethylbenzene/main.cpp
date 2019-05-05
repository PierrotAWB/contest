#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[21];
bool vis[21];

bool hasXylene(int s, int t, int l) { // s = source, t = target, l = length (decrementor)
    if (vis[s] && l != 0) return false; // visited node already, but length not hit

    vis[s] == true;

    if (l == 0 && s == t){ // cycle length hit and start and target node match
        return true;
    } else if (l == 0) { // cycle length hit but s and t do not match
        return false;
    } else { // cycle length not yet hit
        for (auto u: adj[s]){
            if (!vis[u] || u == t){
                hasXylene(u, t, l - 1);
            }
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++){ // populate the adjacency list
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    if (N < 6) {
        cout << "NO";
    }

    for (int i = 1; i < 21; i++){
        if (hasXylene(i, i, 6)) {
            cout << "YES";
            goto finish;
        }
    }
    cout << "NO";

    finish:
    return 0;
}

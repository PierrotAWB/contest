/**
 *    author: awb29
 *    created: Sat May 20 08:18:54 EDT 2023
**/

#include <iostream>
#include <vector>
#include <map>

#define MAX_N 200
using namespace std;


void solve() {
    int n, m;
    cin >> n >> m;

    int u, v;
    vector<int> adj[MAX_N + 1];

    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    map<int, int> deg;
    for (int i = 1; i <= n; ++i) {
        if (deg.find(adj[i].size()) == deg.end()) {
            deg[adj[i].size()] = 1;
        } else {
            deg[adj[i].size()]++;
        }
    }

    /* for (auto u : deg) { */
    /*     cout << u.first << " " << u.second << endl; */
    /* } */

    int x, y;

    if (deg.size() == 2) {
        for (auto it = deg.begin(); it != deg.end(); ++it) {
            if (it->first != 1) {
                x = it->first;
                y = x - 1;
                break;
            }
        }
    } else {
        for (auto it = deg.begin(); it != deg.end(); ++it) {
            if (it->second == 1) {
                x = it->first;
            } else if (it->first != 1) {
                y = it->first - 1;
            }
        }
    }
    cout << x << " " << y << '\n';
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

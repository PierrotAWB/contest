/**
 *    author: awb29
 *    created: Sat May 20 07:58:40 EDT 2023
**/

#include <iostream>
#include <map>
using namespace std;

bool dfs(int curr, int target) {
    if (curr == target) return true;
    if (curr % 3 != 0 || curr < 1) return false;
    int one_third = curr / 3;
    return dfs(one_third, target) || dfs(2 * one_third, target);
}

void solve() {
    int n, m;
    cin >> n >> m;
    cout << (dfs(n, m) ? "YES" : "NO") << '\n';
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

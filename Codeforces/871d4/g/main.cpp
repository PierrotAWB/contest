/**
 *    author: awb29
 *    created: Sat May 20 09:09:03 EDT 2023
**/

#include <iostream>
#include <ratio>
#include <cmath>

using namespace std;

int triangle[1500];


pair<int, int> parents(int n) {
    if (n == 1) return make_pair(-1, -1);
    int idx = *lower_bound(triangle, triangle + 1500, n);
    if (triangle[idx] == n)
        return make_pair(n - idx, -1);
    if (n - triangle[idx - 1] == 1)
        return make_pair(n - idx + 1, -1);
    return make_pair(n - idx, n - idx + 1);
}

void solve() {
    int n;
    cin >> n;
    pair<int, int> p = parents(n);
    cout << p.first << " " << p.second << '\n';
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

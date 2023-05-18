#include <iostream>
#include <vector>

#define MAX_N 1000
#define MAX_M 1000

using namespace std;

int arr[MAX_M][MAX_N];
int vis[MAX_M][MAX_N];
int n, m;

int dfs(int i, int j) {
	if (vis[i][j] || arr[i][j] == 0) return 0;
	int ret = arr[i][j];
	vis[i][j] = 1;
	if (i + 1 < n && arr[i + 1][j] != 0) ret += dfs(i + 1, j);
	if (i - 1 >= 0 && arr[i - 1][j] != 0) ret += dfs(i - 1, j);
	if (j + 1 < m && arr[i][j + 1] != 0) ret += dfs(i, j + 1);
	if (j - 1 >= 0 && arr[i][j - 1] != 0) ret += dfs(i, j - 1);
	return ret;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> arr[i][j];
			vis[i][j] = 0;
		}
	}
	int best = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (arr[i][j] != 0)
				best = max(best, dfs(i, j));
	cout << best << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

/*
ID: andreww7
TASK: subset
LANG: C++11
*/

#include <iostream>
#include <fstream>

#define MAX_N 781

using namespace std; 
int N; 

/* store the number of ways to partition 
the set {1, 2, ..., k} into two subsets whose
sums differ by m at count[k][m] */
long long dp[MAX_N][MAX_N];

long long solve();

int main() {
	ifstream fin("subset.in"); 
	fin >> N; 
	fin.close();

	long long ans = solve();

	ofstream fout("subset.out");
	fout << ans << "\n"; 
	fout.close();
	return 0;
}

long long solve() {
	dp[1][1] = 1;

	// if N is not divisible by 4 (or N + 1), 
	// the sum of numbers up to N, or (N)(N + 1)
	// then it is guaranteed that no 'subset sum'
	// partition exist

	if (N % 4 == 1 || N % 4 == 2) 
		return 0;

	for (int i = 2; i <= N; i++){
		int sum = i * (i + 1) / 2;
		for (int j = 0; j <= sum; j++) {
			if (j != 0) {
				if (i != j)
					dp[i][j] = dp[i - 1][i + j] + 
							   dp[i - 1][abs(i - j)];
				else 
					dp[i][j] = dp[i - 1][i + j] + 2 * dp[i - 1][abs(i - j)];
			} else 
				dp[i][j] = dp[i - 1][i];
		}
	}

	return dp[N][0];
}

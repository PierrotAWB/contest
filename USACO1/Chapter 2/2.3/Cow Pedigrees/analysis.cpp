/*
 ID: andreww7
 PROB: nocows
 LANG: C++
 */

#include <cstdio>
#include <cstdlib>

#include <iostream>

#define MOD 9901

using namespace std;

FILE *fin = fopen("nocows.in", "r");
FILE *fout = fopen("nocows.out", "w");

int dp[101][202], N, H, c;
// smallTrees is an accumulator. smallTrees[i][j] is the number of trees
// of depth AT MOST i (not i exactly, in contrast with dp) and j nodes.
int smallTrees[101][202];

int main() {
	fscanf(fin, "%d %d", &N, &H);
	if (N % 2 == 0) {
		fputs("0\n", fout); 
		return 0;
	}
	dp[1][1] = 1;
	for (int depth = 2; depth <= H; ++depth) {
		for (int n_nodes = 1; n_nodes <= N; n_nodes+=2) {
			for (int n_left = 1; n_left <= n_nodes - 1 - n_left; n_left+=2) {
				c = (n_left != n_nodes - 1 - n_left) ? 2 : 1;
				dp[depth][n_nodes] += c * 
					(smallTrees[depth - 2][n_left] * dp[depth - 1][n_nodes - 1 - n_left] +
					dp[depth - 1][n_left] * smallTrees[depth - 2][n_nodes - 1 - n_left] + 
					dp[depth - 1][n_left] * dp[depth - 1][n_nodes - 1 - n_left]);
				dp[depth][n_nodes] %= MOD;
				// cout << depth << " " << n_nodes << " " << n_left << " | " << dp[depth][n_nodes] << endl;
			}
		}		
		for (int k = 0; k <= N; ++k) {
			smallTrees[depth - 1][k] += dp[depth - 1][k] + smallTrees[depth - 2][k];
			smallTrees[depth - 1][k] %= MOD;
		}
	}
	fprintf(fout, "%d\n", dp[H][N]);
	return 0;
}

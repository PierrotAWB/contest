/*
ID: andreww7
PROB: concom
LANG: C++11
*/

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <queue>
#include <stdlib.h>
#include <vector>

using namespace std;

FILE *fin = fopen("concom.in", "r");
FILE *fout = fopen("concom.out", "w");

vector<int> v[101];
int influence[101][101];
bool visited[101];

bool in(int j, vector<int> v) {
	for (auto u : v) if (u == j) return true;
	return false;
}

// Given a list, r, of the companies controlled by A,
// compute the total influence
int combined_influence(vector<int> r, int source, int target) {
	int acc = influence[source][target];
	for (auto u : r) acc += influence[u][target];
	return acc;
}

vector<int> bfs(int s) {
	vector<int> res; queue<int> q;
	// cout << "BFS for node " << s << endl;
	for (int i = 1; i <= 100; ++i) {
		if (i != s && influence[s][i] > 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		if (visited[q.front()]) {
			// check if combined_influence now exceeds 50 
			// this might happen if the company s attains enough control AFTER visiting the node.
			if (combined_influence(res, s, q.front()) > 50 && !in(q.front(), res)) res.push_back(q.front());
			q.pop();
			continue;
		}
		visited[q.front()] = true;
		for (auto u : v[q.front()]) q.push(u);
		if (combined_influence(res, s, q.front()) > 50) res.push_back(q.front());	
		q.pop();
	}

	return res;
}

int main() {
	int n; 
	fscanf(fin, "%d", &n);
	for (int i = 0; i < n; i++) {
		int A, B, cont;
		fscanf(fin, "%d %d %d", &A, &B, &cont);
		v[A].push_back(B);
		influence[A][B] = cont;
	}
	
	// indirect control
	for (int i = 1; i <= 100; ++i) {
		vector<int> ans = bfs(i);
		sort(ans.begin(), ans.end());
		for (auto u : ans) if (i != u) fprintf(fout, "%d %d\n", i, u);
		for (int j = 1; j <= 100; ++j) visited[j] = false;
	}

	return 0;
}

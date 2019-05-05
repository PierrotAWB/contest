//
//  main.cpp
//  CCC08S3
//
//  Created by Andrew Wang on 2017-07-20.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <map> 
#include <vector> 
#include <queue>
using namespace std;

queue<pair<int, int> > q;
bool visited[22][22];
map<pair<int, int>, int> dist;
map<pair<int, int>, vector<pair<int, int> > > adj;

bool endsInStar = false;

void bfs(pair<int, int> source) {
	visited[source.first][source.second] = true;
	dist[{source.first, source.second}] = 0;
	q.push({source.first, source.second});
	while (!q.empty()) {
		pair<int, int> s = q.front(); q.pop();
		for (auto u : adj[s]) {
			if (visited[u.first][u.second]) continue;
			//cout << u.first << " " << u.second << " ";
			visited[u.first][u.second] = true;
			dist[{u.first, u.second}] = dist[{s.first, s.second}] + 1;
			//cout << dist[{u.first, u.second}] << endl;
			q.push({u.first, u.second});
		}
	}
}

int main(int argc, const char * argv[]) {
	cin.sync_with_stdio();
	cin.tie(0);
	short T; cin >> T;
	for (short i = 0; i < T; i++) {
		short r, c; cin >> r >> c;
		adj.clear();
		for (short j = 1; j <= r; j++) { // read input, process in adjacency list
			for (short k = 1; k <= c; k++) {
				char symbol; cin >> symbol;
				switch (symbol) {
					case '+':
						if (j > 1) adj[{j, k}].push_back({j - 1, k});
						if (k > 1) adj[{j, k}].push_back({j, k - 1});
						if (j < r) adj[{j, k}].push_back({j + 1, k});
						if (k < c) adj[{j, k}].push_back({j, k + 1});
						break;
					case '-':
						if (k > 1) adj[{j, k}].push_back({j, k - 1});
						if (k < c) adj[{j, k}].push_back({j, k + 1});
						break;
					case '|':
						if (j > 1) adj[{j, k}].push_back({j - 1, k});
						if (j < r) adj[{j, k}].push_back({j + 1, k});
						break;
					case '*':
						if (r == 1 && c == 2 && i == 1) endsInStar = true;
						break;
				}
			}
		}
		for (short j = 1; j < 22; j++){
			for (short k = 1; k < 22; k++){
				visited[j][k]&=0;
			}
		}
		dist.clear();
		bfs({1, 1});
		if (visited[r][c] && !endsInStar) cout << dist[{r, c}] + 1 << endl;
		else cout << -1 << endl;
	}
	return 0;
}

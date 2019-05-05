//
//  main.cpp
//  animeConventions
//
//  Created by Andrew Wang on 2017-07-06.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

bitset<100001> visited;
vector<int> adj[100001];

void dfs(int s, int t) {
	if (visited[s]) return;
	visited[s] = true;
	if (visited[t]) return;
	for (auto u : adj[s]) {
		dfs(u, t);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, Q;
	cin >> N >> Q;
	
	for(int i = 0; i < Q; i++) {
		char prompt;
		
		cin >> prompt;
		
		if (prompt == 'A') {
			int c1, c2;
			cin >> c1 >> c2;
			adj[c1].push_back(c2);
			adj[c2].push_back(c1);
		
		} else if (prompt == 'Q'){
			int c1, c2;
			cin >> c1 >> c2;
			visited.reset();
			dfs(c1, c2);
			if (visited[c2]) cout << "Y\n";
			else cout << "N\n";
		}
	}
	return 0;
}

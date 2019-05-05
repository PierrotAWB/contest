//
//  main.cpp
//  SingleSourceShortestPathDjikstra
//
//  Created by Andrew Wang on 2017-07-03.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int> > adj[1001]; // (b, w)
bool processed[1001];

int main(int argc, const char * argv[]) {
	priority_queue<pair<int, int> > q; // (d, n)
	
	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	
	// Djikstra's algorithm
	const int INF = 10001;
	int distance[N + 1];
	
	for (int i = 1; i <= N; i++) distance[i] = INF;
	distance[1] = 0;
	q.push({0, 1});
	while (!q.empty()) {
		int a  = q.top().second; q.pop();
		if (processed[a]) continue;
		processed[a] = true;
		
		for (auto u : adj[a]) {
			int b = u.first, w = u.second;
			if (distance[a] + w < distance[b]) {
				distance[b] = distance[a] + w;
				q.push({-distance[b], b});
			}
		}
	}
	
	// Output section
	for (int i = 1; i <= N; i++) {
		if (distance[i] == INF) {
			cout << -1 << endl;
		} else {
			cout << distance[i] << endl;
		}
	}
	
	return 0;
}

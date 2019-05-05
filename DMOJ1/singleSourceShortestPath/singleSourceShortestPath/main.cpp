//
//  main.cpp
//  singleSourceShortestPath
//
//  Created by Andrew Wang on 2017-07-03.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//
//  Use of the Bellman-Ford algorithm.

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<tuple<int, int, int> > edges; // in the form (a, b, w)

int main(int argc, const char * argv[]) {
	int N, M;
	cin >> N >> M;
	
	// store all weighted edges into the edge list
	for (int i = 0; i < M; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		edges.push_back(tie(a, b, w));
	}
	
	// Bellman-Ford algorithm
	const int INF = 10001;
	int distance[N + 1];
	
	for (int i = 1; i <= N; i++) {
		distance[i] = INF;
	}
	
	distance[1] = 0;
	
	for (int i = 1; i <= N - 1; i++) {
		for (auto e : edges) {
			int a, b, w;
			tie(a, b, w) = e;
			distance[b] = min(distance[b], distance[a] + w);
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

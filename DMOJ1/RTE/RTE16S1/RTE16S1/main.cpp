//
//  main.cpp
//  RTE16S1
//
//  Created by Andrew Wang on 2017-07-07.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

long long maxTriangles(long long N, long long K) {
	long long upperBound = 6 * (N - K);
	long long i = floor(pow(upperBound, 1 / (double) 3)) - 1; // estimate;
	
	while (i * (i + 1) * (i + 2) <= upperBound) {
		i++;
	}
	
	i--; // for last iteration
	
	return i;
}

long long numTriangles(long long maxTriangles) {
	return (maxTriangles * (maxTriangles + 1) * (maxTriangles + 2) / 6);
}

int main(int argc, const char * argv[]) {
	ios::sync_with_stdio();
	cin.tie(0);
	
	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		long long N, K;
		cin >> N >> K;
		
		cout << numTriangles(maxTriangles(N, K)) << "\n";
	}
	return 0;
}

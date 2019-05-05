//
//  main.cpp
//  Marathon
//
//  Created by Andrew Wang on 2017-07-16.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
	ios::sync_with_stdio();
	cin.tie(0);
	
	int accumulator[500001];
	
	int N, Q;
	cin >> N >> Q;
	
	cin >> accumulator[1];
	
	for (int i = 2; i <= N; i++) {
		int delta;
		cin >> delta;
		accumulator[i] = accumulator[i - 1] + delta;
	}
	
	int total = accumulator[N];
	
	for (int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;
		cout << total - (accumulator[b] - accumulator[a - 1]) << endl;
	}
	
	return 0;
}

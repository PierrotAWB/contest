//
//  main.cpp
//  TheOddNumber
//
//  Created by Andrew Wang on 2017-07-18.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <unordered_set>
using namespace std;

int main(int argc, const char * argv[]) {
	
	unordered_multiset<int> m;

	cin.sync_with_stdio();
	cin.tie(0);
	
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		m.insert(k);
	}
	
	return 0;
	
//	for (auto u : m) {
//		if (m.count(u) % 2 != 0) {
//			cout << u << endl;
//			break;
//		}
//	}
//	
//	return 0;
}

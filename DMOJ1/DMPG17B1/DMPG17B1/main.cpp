//
//  main.cpp
//  DMPG17B1
//
//  Created by Andrew Wang on 2017-07-07.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> p, pair<int, int> q) { // is cost lower and time longer?
	if (p.second != q.second) return p.second > q.second;
	else return p.first < q.first;
}

int main(int argc, const char * argv[]) {
	int N;
	cin >> N;
	
	pair<int, int> membership[N];
	
	for (int i = 0; i < N; i++) {
		int ci, di;
		cin >> ci >> di;
		
		membership[i] = {ci, di};
	}
	
	sort(membership, membership + N, cmp);
	cout << membership[0].first << " "  << membership[0].second << endl;
	return 0;
}

//
//  main.cpp
//  TLE15P1
//
//  Created by Andrew Wang on 2017-07-04.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool comp(pair<string, int> p, pair<string, int> q) {
	return p.second >= q.second;
}

int main(int argc, const char * argv[]) {

	int N, P;
	cin >> N >> P;
	
	pair<string, int> minutes[N];
	
	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;
		minutes[i] = {name, 0};
	}
	
	for (int i = 0; i < P; i++) {
		for (int j = 0; j < N; j++) {
			int time;
			cin >> time;
			minutes[j].second += time;
		}
	}
	
	sort(minutes, minutes + N, comp);
	
	for (int i = 0; i < N; i++) {
		cout << i + 3 << ". " << minutes[i].first << endl;
	}
	
	return 0;
}

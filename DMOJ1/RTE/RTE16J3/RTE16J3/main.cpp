//
//  main.cpp
//  RTE16J3
//
//  Created by Andrew Wang on 2017-07-03.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		int N, C;
		cin >> N >> C;
		
		int mule[1001] = {0};
		bool hasAbility[1001];
		
		for (int j = 1; j <= 1000; j++) {
			hasAbility[j] = true;
		}
		
		for (int j = 0; j < C; j++) {
			string prompt;
			cin >> prompt;
			if (prompt == "A") {
				int n, x;
				cin >> n >> x;
				if (hasAbility[x]) mule[x] += n;
			} else if (prompt == "Q") {
				int x;
				cin >> x;
				cout << mule[x] << endl;
			} else if (prompt == "G") {
				int x;
				int accumulator = 0;
				cin >> x;
				for (int k = 1; k <= x; k++) {
					accumulator += mule[k];
				}
				cout << accumulator << endl;
			} else if (prompt == "L") {
				int x;
				int accumulator = 0;
				cin >> x;
				for (int k = N; k >= N - x + 1; k--) {
					accumulator += mule[k];
				}
				cout << accumulator << endl;
			} else {
				int x;
				cin >> x;
				hasAbility[x] = false;
				mule[x] = 0;
			}
		}
	}
	return 0;
}

//
//  main.cpp
//  UnevenSand
//
//  Created by Andrew Wang on 2017-07-16.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
	ios::sync_with_stdio();
	cin.tie(0);
	unsigned int k = 1e9;
	unsigned int u = 2e9, l = 1;
	cout << k << "\n" << flush;
	string s;
	while (cin >> s) {
		if (s == "OK") break;
		else if (s == "SINKS") { // pressure too low; go higher
			l = k; // lowerbounded by k
			k = (k + u) / 2; // next guess
		} else { // pressure too high; go lower
			u = k; // upperbounded by k
			k = (k + l) / 2; // next guess
		}
		cout << k << "\n" << flush;
	}
	return 0;
}

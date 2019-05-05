//
//  main.cpp
//  GaussianElimination
//
//  Created by Andrew Wang on 2017-07-16.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
	int N, M;
	cin >> N >> M;
	if (N == 1 || M == 1) cout << "First";
	else {
		if ((N + M) % 2 == 1) cout << "First";
		else cout << "Second";
	}
	return 0;
}

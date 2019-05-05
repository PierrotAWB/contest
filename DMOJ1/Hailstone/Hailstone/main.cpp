//
//  main.cpp
//  Hailstone
//
//  Created by Andrew Wang on 2017-07-14.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
using namespace std;

int collatz(int N) {
	int counter = 0;
	while (N!=1) {
		if (N % 2 == 0) N /= 2;
		else N = 3 * N + 1;
		counter++;
	}
	return counter;
}

int main(int argc, const char * argv[]) {
	ios::sync_with_stdio();
	cin.tie(0);
	int N;
	cin >> N;
	cout << collatz(N);
	return 0;
}

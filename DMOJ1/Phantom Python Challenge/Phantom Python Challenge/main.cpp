//
//  main.cpp
//  Phantom Python Challenge
//
//  Created by Andrew Wang on 2017-07-07.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
	bool result = (n % 2 == 0 and n == 2);
//	for (int i = 3; i < pow(n, 0.5); i+=2) {
//		result = result || n % i == 0;
//	}
	return result;
}

int main(int argc, const char * argv[]) {
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int Q;
		cin >> Q;
		cout << isPrime(Q) << endl;
	}
	return 0;
}

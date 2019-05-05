//
//  main.cpp
//  nextSemiPrime
//
//  Created by Andrew Wang on 2017-07-04.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <bitset>
using namespace std;

bitset<1000000> candidate;
int main(int argc, const char * argv[]) {
	int Q;
	cin >> Q;
	
	// sieve primes and find semi primes
	for (int i = 2; i < candidate.size(); i++) {
		candidate[i] = candidate[i]|1;
	}
	
	for (int i = 2; i < candidate.size(); i++) {
		if (candidate[i]) { // prime found
			for (int j = 2; j <= candidate.size() / i; j++) {
				candidate[i * j] = candidate[i * j]&0;
			}
		}
	}
	
	// prompt and return
	for (int i = 0; i < Q; i++) {
		int N;
		cin >> N;
		
		bool semiPrimeFound = false;
		int incrementor = N + 1;
		
		while (!semiPrimeFound) {
			if (candidate[incrementor]) {
				semiPrimeFound = true;
				cout << incrementor << endl;
			}
			incrementor++;
		}
	}
	return 0;
}

//
//  main.cpp
//  mockCCCDupvoting
//
//  Created by Andrew Wang on 2017-07-10.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//
// INCOMPLETE

#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main(int argc, const char * argv[]) {
	int P, U, R1, R2;
	cin >> P >> U >> R1 >> R2;
	
	int numWays = 0;
	
	R1 /= gcd(R1, R2);
	R2 /= gcd(R1, R2);
	
	// R1 dup : R2 up
	for (int i = 1; i <= U / (R1 + R2); i++) {
		if (2 * R1 * i + R2 * i - P >= 0 && (2 * R1 * i + R2 * i - P) % 1 == 0) {
			if (R1 * i + R2 * i + (2 * R1 * i + R2 * i - P) == U) numWays ++;
		}
		else break;
	}
	
	// R1 up: R2 dup
	for (int i = 1; i <= U / (R1 + R2); i++) {
		if (R1 * i + 2 * R2 * i - P >= 0 && (R1 * i + 2 * R2 * i - P) % 1 == 0) {
			if (R1 * i + R2 * i + (R1 * i + 2 * R2 * i - P) == U) numWays++;
		}
		else break;
	}
	
	// R1 dup : R2 down
	for (int i = 1; i <= U / (R1 + R2); i++) {
		if (P - 2 * (R1 * i) + (R2 * i) >= 0 && (P - 2 * (R1 * i) + (R2 * i)) % 1 == 0) {
			if (R1 * i + R2 * i + (P - 2 * (R1 * i) + (R2 * i)) == U) numWays++;
		}
		else break;
	}
	
	// R1 down: R2 dup
	for (int i = 1; i <= U/(R1 + R2); i++) {
		if (P + (R1 * i) - 2 * (R2 * i) >= 0 && (P + (R1 * i) - 2 * (R2 * i)) % 1 == 0) {
			if (R1 * i + R2 * i + P + (R1 * i) - 2 * (R2 * i) == U) numWays ++;
		}
		else break;
	}
	
	// R1 up : R2 down
	for (int i = 1; i <= U/(R1 + R2); i++) {
		if ((P - R1 * i + R2 * i)/(double)2 >= 0 && remainder((P - R1 * i + R2 * i)/ (double) 2, 1) == 0){
			if (R1*i + R2*i + round((P - R1 * i + R2 * i)/(double)2) == U) numWays++;
		}
		else break;
	}
	
	// R1 down : R2 up
	for (int i = 1; i <= U/(R1 + R2); i++) {
		if ((P + R1 * i - R2 * i)/(double)2 >= 0 && remainder((P + R1 * i - R2 * i)/(double) 2, 1) == 0) {
			if (R1*i + R2*i + round(P + R1 * i - R2 * i)/(double)2 == U) numWays++;
		}
	}
	
	cout << numWays / 2 << endl; // double counted initially
	return 0;
}

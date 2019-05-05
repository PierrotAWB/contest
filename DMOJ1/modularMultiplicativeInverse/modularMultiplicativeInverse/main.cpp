//
//  main.cpp
//  modularMultiplicativeInverse
//
//  Created by Andrew Wang on 2017-07-05.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

long long inverse (unsigned long long a, unsigned long long n) {
	long long t = 0, newT = 1, r = n, newR = a;
	while (newR != 0) {
		auto divRes = lldiv(r, newR);
		long long quotient = divRes.quot;
		long long tempT = t, tempR = r;
		t = newT;
		newT = tempT - quotient * newT;
		r = newR;
		newR = tempR - quotient * newR;
	}
	if (t < 0) t += n;
	return t;
}

int main() {
	unsigned long long N, M;
	cin >> N >> M;
	
	cout << inverse(N, M) << endl;
}

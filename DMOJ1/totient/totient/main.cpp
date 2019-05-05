//
//  main.cpp
//  totient
//
//  Created by Andrew Wang on 2017-07-06.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <bitset>
#include <cmath>
#include <set>
#include <vector>

using namespace std;

bitset<1000001> candidate;
vector<int> primes;

void genPrimes() {
	for (int i = 2; i < candidate.size(); i++) {
		candidate[i] = candidate[i]|1;
	}
	
	for (int i = 2; i < candidate.size(); i++) {
		if (candidate[i]) {
			for (int j = 2; j <= candidate.size() / i; j++) {
				candidate[i * j] = candidate[i * j]&0;
			}
		}
	}
	
	for (int i = 2; i < candidate.size(); i++) {
		if (candidate[i]){
			primes.push_back(i);
		}
	}
}

bool exponentiallyExpressible(int n) { // f in the definition
	if (n == 1) return true;
	double upperBound = log2(n);
	for (int i = 2; i <= upperBound; i++) {
		if (remainder(pow(n, 1/(double)i), 1) == 0) return true;
	}
	return false;
}

set<int> primeDivisors(int n) {
	set<int> primeDivs;
	const double upperBound = pow(n, 0.5);
	for (auto u : primes) {
		if (u > upperBound) break;
		if (n % u == 0) {
			primeDivs.insert(u);
			while (n % u == 0) n /= u;
		}
	}
	if (n > 1) primeDivs.insert(n);
	return primeDivs;
}

int totient(int n) {
	int product = n;
	set<int> s = primeDivisors(n);
	for (auto u : s) {
		product *= (1 - 1 / (double) u);
	}
	return product;
}

int g(int y) {
	int result = 0;
	for (int i = 0; i <= y; i++) {
		result += exponentiallyExpressible(totient(i)) * totient(i);
	}
	return result % 1000000007;
}

int main() {
	ios::sync_with_stdio();
	cin.tie(0);
	
	int N;
	cin >> N;
	
	genPrimes();
	cout << g(N);
	
	return 0;
}

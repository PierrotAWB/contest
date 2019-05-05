//
//  main.cpp
//  fibonacci
//
//  Created by Andrew Wang on 2017-07-04.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
using namespace std;

pair<int, int> fib(int n) {
	if (n == 0) {
		return {0, 1};
	} else {
		int a = fib(n/2).first, b = fib(n/2).second;
		int c = a * (b * 2 - a);
		int d = a * a + b * b;
		if (n % 2 == 0) {
			return {c, d};
		} else {
			return {d, c + d};
		}
	}
}

int main(int argc, const char * argv[]) {
	int n;
	cin >> n;
	
	cout << fib(n).first % 1000000007 << endl;
	return 0;
}

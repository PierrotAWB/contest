//
//  main.cpp
//  ThirdCellar
//
//  Created by Andrew Wang on 2017-07-04.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <bitset>

using namespace std;

bitset<1000000> candidate; // 1 - 999999

int main() {
	int N, a, b;
	cin >> N;
	
	for (int i = 2; i < candidate.size(); i++) {
		candidate[i] = candidate[i]|1;
	}
	
	for (int i = 2; i < candidate.size(); i++) {
		if (candidate[i]) {
			for (int j = 2; j <= 1000000 / i; j++) {
				candidate[i * j] = candidate[i * j]&0;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		int counter = 0;
		for (int j = a; j < b; j++) {
			if (candidate[j]) counter ++;
		}
		cout << counter << endl;
	}
	return 0;
}

//
//  main.cpp
//  calcPoints
//
//  Created by Andrew Wang on 2017-07-04.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
	double P = 0, B;
	int n;
	cin >> n;
	
	B = 150 * ( 1 - pow(0.997, n));
	
	double score[n];
	
	for (int i = 0; i < n; i++) {
		cin >> score[n];
	}
	
	sort(score, score + n);
	
	for (int i = 0; i < n; i++) {
		P += 0.95 * i * score[i];
	}
	
	cout << P + B;
	return 0;
}

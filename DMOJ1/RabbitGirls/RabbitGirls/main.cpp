//
//  main.cpp
//  RabbitGirls
//
//  Created by Andrew Wang on 2017-07-16.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]) {
	
	ios::sync_with_stdio();
	cin.tie(0);
	
	long N, K;
	long double ans;
	cin >> N >> K;
	
	long double divRes = N / (long double) K;
	
	int a = floor(divRes); 
	int	b = a + 1; 

	cout << a*K << " " << b*K << endl;

	ans = min(N - a*K, b*K - N);

	cout << fixed << ans << endl;
	return 0;
}
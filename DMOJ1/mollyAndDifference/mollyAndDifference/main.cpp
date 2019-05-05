//
//  main.cpp
//  mollyAndDifference
//
//  Created by Andrew Wang on 2017-07-06.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
	int N;
	cin >> N;
	
	long long A[N];
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	sort(A, A + N);
	
	long long d = 1000000000000000000;

	for (int i = 0; i < N - 1; i++) {
		if (abs(A[i] - A[i + 1]) < d) d = abs(A[i] - A[i + 1]);
	}
	
	cout << d << endl;
	
	return 0;
}

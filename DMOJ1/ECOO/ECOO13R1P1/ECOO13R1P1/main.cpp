//
//  main.cpp
//  ECOO13R1P1
//
//  Created by Andrew Wang on 2017-07-07.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <string> 
using namespace std;

int main(int argc, const char * argv[]) {
	int N;
	cin >> N;
	
	string query;
	int late = 0, served = 0, left;

	while (cin >> query) {
		if (query == "EOF") break;
		else if (query == "TAKE") {
			late++;
			if (N < 999) N++;
			else N = 1;
		}
		else if (query == "SERVE") served++;
		else {
			left = late - served;
			cout << late << " " << left << " " <<  N << endl;
			late = 0;
			served = 0;
		}
	}
	return 0;
}

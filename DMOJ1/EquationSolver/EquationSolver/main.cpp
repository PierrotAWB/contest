//
//  main.cpp
//  EquationSolver
//
//  Created by Andrew Wang on 2017-07-17.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
	int runSum;
	string s;
	cin >> runSum;
	while (cin >> s) {
		if (s == "=") break;
		int k;
		cin >> k;
		if (s == "P") runSum += k;
		if (s == "M") runSum -= k;
	}
	cout << runSum;
	return 0;
}

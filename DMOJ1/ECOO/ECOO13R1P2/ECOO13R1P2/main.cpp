//
//  main.cpp
//  ECOO13R1P2
//
//  Created by Andrew Wang on 2017-07-07.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <string> 
#include <cmath>

using namespace std;

string checkDig(string baseNum) {
	int accumulator = 0, checkDig;
	
	// step 1
	for (int i = baseNum.length() - 1; i >= 0; i -= 2) {
		if ((int) baseNum.at(i) - 48 < 5) accumulator += 2 * ((int)baseNum.at(i) - 48);
		else accumulator += (int) 2 * ((int) baseNum.at(i) - 48) - 9;
	}
	
	for (int i = baseNum.length() - 2; i >= 0; i -= 2) {
		accumulator += (int) baseNum.at(i) - 48;
	}
	
 checkDig = int(round(10 * (ceil(accumulator / (double) 10) - accumulator / (double) 10)));
	
	return to_string(checkDig);
}

int main(int argc, const char * argv[]) {
	for (int i = 0; i < 5; i++) {
		string result = "";
		for (int j = 0; j < 5; j++) {
			string baseNum;
			cin >> baseNum;
			result += checkDig(baseNum);
		}
		cout << result << "\n";
	}
	return 0;
}

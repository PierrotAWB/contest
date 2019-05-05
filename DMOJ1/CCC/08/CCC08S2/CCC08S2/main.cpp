//
//  main.cpp
//  CCC08S2
//
//  Created by Andrew Wang on 2017-07-03.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int countPennies (int radius) {
	const int radiusSquared = radius * radius;
	int pennyCounter = 4 * radius + 1;
	
	// count pennies in one quadrant, multiply by 4 and add to counter
	int quadrantPennyCounter = 0;
	for (int x = 1; x < radius; x++) {
		quadrantPennyCounter += (int) floor(sqrt(radiusSquared - x * x));
	}
	
	pennyCounter += 4 * quadrantPennyCounter;
	return pennyCounter;
}

int main(int argc, const char * argv[]) {
	int r;
	while (cin >> r) {
		if (r == 0) break;
		
		cout << countPennies(r) << endl;
	}
	return 0;
}

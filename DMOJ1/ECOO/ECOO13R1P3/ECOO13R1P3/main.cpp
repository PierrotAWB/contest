//
//  main.cpp
//  ECOO13R1P3
//
//  Created by Andrew Wang on 2017-07-07.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

char entries[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int main(int argc, const char * argv[]) {
	for (int i = 0; i < 10; i++) {
		char hex[17][17];
		
		for (int j = 1; j <= 16; j++) { // input
			for (int k = 1; k <= 16; k++) {
				cin >> hex[j][k];
			}
		}
		
		int moveCounter = 0;
		
		for (int j = 1; j <= 16; j++) { // fill in and count moves
			for (int k = 1; k <= 16; k++) {
				if ((int) hex[j][k] == 45){
					for (auto u : entries) {
						if (find(hex[j], hex[j] + 17, u) == &hex[j] + 17) continue; // if char in row, skip to next candidate
					}
				}
			}
		}
	}
	return 0;
}

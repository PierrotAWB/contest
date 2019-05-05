//
//  main.cpp
//  RTE16J1
//
//  Created by Andrew Wang on 2017-07-03.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	getline(cin, s);
	
	int lCounter = 0;
	int maxConsecL = 0;
	int tempConsecL = 0;
	
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) == 'L') {
			lCounter ++;
			tempConsecL ++;
			if (tempConsecL > maxConsecL) maxConsecL = tempConsecL;
		} else if (s.at(i) != ' '){
			tempConsecL = 0;
		}
	}
	
	cout << lCounter << " " << maxConsecL << endl;
	return 0;
}

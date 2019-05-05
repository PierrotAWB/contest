//
//  main.cpp
//  TLE16P2
//
//  Created by Andrew Wang on 2017-07-13.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <string> 

using namespace std;

string toBinary(int N) {
	string binString = "";
	
	while (N >= 1) {
		if (N % 2 != 0) binString = "1" + binString;
		else binString = "0" + binString;
		N /= 2;
	}
	
	while (binString.at(0) == '0') {
		binString.erase(0, 1);
	}
	
	return binString;
}

int main(int argc, const char * argv[]) {
	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		
		string binString = toBinary(N);
		for (int j = 0; j < binString.length(); j++){
			if (binString.at(j) == '1') cout << "dank ";
			else cout << "meme ";
		}
		cout << endl;
	}
	
	return 0;
}

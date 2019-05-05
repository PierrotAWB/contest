//
//  main.cpp
//  CCCJQRP3
//
//  Created by Andrew Wang on 2017-07-17.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int absoluteVal(int n) {
	if (n < 0) return -n;
	else return n;
}

string add(string a, string b){
	int lenDiff = absoluteVal(a.length() - b.length());
	if (lenDiff != 0) {
		string zeroPad(lenDiff, '0');
		if (a.length() < b.length()) {
			a = zeroPad + a;
		} else {
			b = zeroPad + b;
		}
	}
	
	string answer = "";
	int carry = 0;
	for (int i = a.length() - 1; i >= 0 ; i--) {
		int sum = (int) a.at(i) + (int) b.at(i) + carry - 96;
		div_t dv = div(sum, 10);
		answer = to_string(dv.rem) + answer;
		carry = dv.quot;
	}
	
	if (carry != 0){
		answer = to_string(carry) + answer;
	}
	return answer;
}

int main(int argc, const char * argv[]) {
	string a, b, c;
	cin >> a >> b >> c;
	string ab = add(a, b);
	cout << add(ab, c);
	return 0;
}

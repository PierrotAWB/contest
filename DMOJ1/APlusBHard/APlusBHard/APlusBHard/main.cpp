//
//  main.cpp
//  APlusBHard
//
//  Created by Andrew Wang on 2017-07-02.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int absoluteVal(int c){
    (c >= 0) ? c = c: c*= -1;
    return c;
}

bool comp(string a, string b){ // a > b?
	if (a.length() != b.length()){
		return a.length() > b.length();
	}
	
	for (int i = 0; i < a.length(); i++) {
		if (a.at(i) != b.at(i)) {
			return (int) a.at(i) > (int) b.at(i);
		}
	}
	
	return false;
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

string subtract(string a, string b){
	if (a == b) return "0";
	
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
	
	if (comp(a, b)) { // a > b
		for (int i = a.length() - 1; i >= 0; i--) {
			int difference = (int) a.at(i) - (int) b.at(i);
			if (difference < 0) {
				difference += 10;
				a.at(i - 1) = (char) (int) a.at(i - 1) - 1;
			}
			answer = to_string(difference) + answer;
		}
	} else { // a <= b
		for (int i = a.length() - 1; i >= 0; i--) {
			int difference = (int) b.at(i) - (int) a.at(i);
			if (difference < 0) {
				difference += 10;
				b.at(i - 1) = (char) (int) b.at(i - 1) - 1;
			}
			answer = to_string(difference) + answer;
		}
	}
	
	// check if there are leading zeros?
	if (answer.at(0) == '0') { // yes there are.
		while (answer.at(0) == '0') answer.erase(0, 1);
	}
	
	if (!comp(a, b)) {
		answer = "-" + answer;
	}
	return answer;
}

int main(){
    int N;
    cin >> N;
	
    for (int i = 0; i < N; i++){
        string a, b;
        cin >> a >> b;
        if (a.at(0) != '-' && b.at(0) != '-') {
            cout << add(a, b) << endl;
        } else if (a.at(0) == '-' && b.at(0) == '-') {
            a.erase(0, 1); b.erase(0, 1);
            cout << "-" << add(a, b) << endl;
        } else if (a.at(0) != '-' && b.at(0) == '-') {
            b.erase(0, 1);
            cout << subtract(a, b) << endl;
        } else {
            a.erase(0, 1);
            cout << subtract(b, a) << endl;
        }
    }
    return 0;
}

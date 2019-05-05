//
//  main.cpp
//  mockCCC416
//
//  Created by Andrew Wang on 2017-07-10.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
	string phoneNumber;
	getline(cin, phoneNumber);
	
	if (phoneNumber.substr(0, 3) != "416" && phoneNumber.substr(0, 3) != "647" && phoneNumber.substr(0, 3) != "437") {
		cout << "invalid";
		goto finish;
	} else if (phoneNumber.at(4) == ' ') {
		cout << "invalid";
		goto finish;
	} else if (phoneNumber.at(3) != ' ') {
		cout << "invalid";
		goto finish;
	} else if (phoneNumber.length() != 11) {
		cout << "invalid";
		goto finish;
	}
	
	if (phoneNumber.substr(0, 3) == "416") cout << "valuable";
	else if (phoneNumber.substr(0, 3) == "647" ||phoneNumber.substr(0, 3) == "437" ) cout << "valueless";
	
finish:
	return 0;
}

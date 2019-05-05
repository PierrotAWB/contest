//
//  main.cpp
//  TLE16P1
//
//  Created by Andrew Wang on 2017-07-13.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> pageTemplate;

int main(int argc, const char * argv[]) {
	string T;
	int N;
	
	cin >> T;
	
	for (int i = 1; i < T.length(); i++) {
		pageTemplate.push_back(T.at(i));
	}
	
	cin >> N;
	int numLetters = pageTemplate.size();
	
	for (int i = 0; i < N; i++) {
		string page;
		cin >> page;
		
		if (page.length() < numLetters) {
			cout << "no" << endl;
			continue;
		}
		
		// verify that every letter in template is in the page
		for (int j = 0; j < pageTemplate.size(); j++) {
			if (count(page.begin(), page.end(), pageTemplate[j]) == 0) {
				cout << "no" << endl;
				goto nextPage;
			}
		}
		cout << "yes" << endl;
	nextPage:
		continue;
	}
	
	return 0;
}

//
//  main.cpp
//  RTE16J2
//
//  Created by Andrew Wang on 2017-07-03.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

multiset<int> student[3];
int main() {
	int Q;
	cin >> Q;
	
	for (int i = 0; i < Q; i++){
		string prompt;
		cin >> prompt;
		
		if (prompt == "ADD") {
			string ci;
			int mi;
			cin >> ci >> mi;
			if (ci == "BLUE") {
				student[0].insert(mi);
			} else if (ci == "PINK") {
				student[1].insert(mi);
			} else {
				student[2].insert(mi);
			}
		} else {
			bool empty = true;
			for (int i = 0; i < 3; i++) {
				if (empty == false) break;
				if (student[i].size() != 0) {
					if (i == 0) cout << "BLUE ";
					else if (i == 1) cout << "PINK ";
					else cout << "GREEN ";
					
					multiset<int>::iterator it;
					it = student[i].begin();
					cout << *it << endl;
					student[i].erase(student[i].find(*it));
					empty = false;
				}
			}
			if (empty == true) {
				cout << "NONE" << endl;
			}
		}
	}
	return 0;
}

//
//  main.cpp
//  mockCCCLowestExamMark
//
//  Created by Andrew Wang on 2017-07-10.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
	int P, Q, W;
	cin >> P >> Q >> W;
	
	double currentAvg = P * (1 - W/(double)100);
	double examMark = (Q - 0.5 - currentAvg) / (W / (double) 100);
	
	if (examMark < 0) cout << 0;
	else if (examMark > 100.01) cout << "DROP THE COURSE";
	else cout << round(examMark);
	return 0;
}

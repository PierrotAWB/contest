//
//  main.cpp
//  TLE16P3
//
//  Created by Andrew Wang on 2017-07-18.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int elementCounter[3]; // C at 0, H at 1, O at 2

int main(int argc, const char * argv[]) {
	ios::sync_with_stdio();
	cin.tie(0);
	
	string R;
	cin >> R;
	R += " "; // quick solution to last char conundrum
	
	/// COUNT ELEMENTS IN R AND STORE THEM IN THEIR APPROPRIATE BUCKETS
	
	int i = 0;
	while (i < R.length() - 1){
		int delta = 1;
		if ((int)R.at(i) < 48 || (int)R.at(i) > 57) {
			if ((int)R.at(i + 1) >= 48 && (int) R.at(i + 1) <= 57) {
				string multiplicity = "";
				int j = i + 1;
				bool isLastCharDigit = ((int)R.at(R.length() - 1) >= 48 && (int)R.at(R.length() - 1) < 57);
				
				while ((int) R.at(j) >= 48 && (int) R.at(j) <= 57) {
					multiplicity += R.at(j);
					if (j >= R.length() - 1 && isLastCharDigit) break;
					j++;
				}
				delta = stoi(multiplicity);
			}
			
			switch(R.at(i)){
				case 'C':
					elementCounter[0] += delta;
					break;
				case 'H':
					elementCounter[1] += delta;
					break;
				case 'O':
					elementCounter[2] += delta;
					break;
			}
		}
		string temp = to_string(delta);
		i += temp.length();
	}
	
	/// CALCULATE COEFFICIENTS
	
	int c = elementCounter[0]; // number of CO2's
	int a = 1; // by default, there is one R
	double b, d;
	
	if (elementCounter[1] % 2 != 0) { // number of H2O's
		d = elementCounter[1];
		c *= 2;
		a *= 2;
	} else d = elementCounter[1] / (double) 2;
	
	b = (2 * c + d - a * elementCounter[2]) / (double) 2;
	
	if (remainder(b, 1) != 0) {
		a *= 2;
		b *= 2;
		c *= 2;
		d *= 2;
	}
	
	/// OUTPUT SECTION
	
	if (c > 0 && d > 0  && b > 0) {
		cout << setprecision(0) << fixed << a << R << " + " << b << "O2 -> " << c <<
		"CO2 + " << d << "H2O" << endl;
	} else {
		cout << "Impossible" << endl;
	}
	
	return 0;
}

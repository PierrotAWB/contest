#include <iostream>
#include <math.h>
#include <cmath>

using namespace std; 

long double minRounder(int ri) { 
	if (ri % 2 == 0) { 
		return (long double) ri - 0.5;
	}
	return ri - 0.5 + 1e-15;
}

long double maxRounder (int ri) { 
	if (ri % 2 == 0) {
		return (long double) ri + (long double) 0.5;
	}
	return ri + 0.5 - 1e-15;
}

long double rem(long double x, long double y) { 
	if (remainder(x, y) >= 0) return remainder(x, y);
	return remainder(x, y) + y;
}

long long sciRound(long double x) { 
	if (rem(x, (long double) 1) > 0.5) return ceil(x);
	if (rem(x, (long double) 1) < 0.5) return floor(x); 
	// x === 0.5 mod 1;
	if (rem(x - 0.5, 2) == 0) { 
		return x - 0.5;
	}
	return round(x);
}

int main() { 
	int N; 
	long double min = 0, max = 0;

	cin >> N; 

	for (int i = 0; i < N; i++) { 
		int ri; 
		cin >> ri; 
		min += minRounder(ri); 
		max += maxRounder(ri);
	}
	//cout.precision(11);
	//cout << fixed <<  min << " " << fixed << max << endl;
	//cout << fixed << rem(min, (long double) 1) << endl;
	cout << sciRound(min) << endl << sciRound(max) << endl;
	return 0;
}
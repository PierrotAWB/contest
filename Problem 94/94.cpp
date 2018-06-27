#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <vector>

#define watch(x) cout << "CURRENT VALUE: " << x << endl;

using namespace std; 

long double MAX = 92604733;//333333334;
long double res = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie();
	cout.precision(16);
	for (long double s = 92604733; s <= MAX+1; s++) {
		if (remainder(s, 1000000) == 0)
			cout << s << "\n";

		// if (remainderl((s+1)*pow((3*s+1)*(s-1), 0.5), 4) == 0) {
		// 	res += 3*s + 1;
		// }
		long double se = 1.5*s + 0.5; 
		if (remainder(pow(se*(se - s)*(se - s)*(se - s - 1), 0.5), 1) == 0) {
			if (2*se <= 1000000000)
				res += 2*se;
			cout << s << " " << s << " " << s + 1 << " " << 2 * se << endl;
		}

		se -= 1; 
		if (remainder(pow(se*(se - s)*(se - s)*(se - s + 1), 0.5), 1) == 0) {
			if (2*se <= 1000000000)
				res += 2*se;
			cout << s << " " << s << " " << s - 1 << " " << 2 * se << endl;
		}

		// if (remainderl((s-1)*pow((3*s-1)*(s+1), 0.5), 4) == 0) {
		// 	res += 3*s - 1;
		}
	cout << res << endl;
	return 0;
}
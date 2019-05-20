/*
ID: andreww7
PROG: kimbits
LANG: C++11
*/

#include <algorithm>
#include <array>
#include <bitset>
#include <cstdio>
#include <deque>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map> 
#include <math.h>
#include <queue>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>

#ifdef __GNUC__
int trailing_ones( uint32_t in) {
	return ~ in == 0? 32 : __builtin_ctz( ~ in );
}
#endif

unsigned trailing_zeroes(int n) {
    unsigned bits = 0, x = n;

    if (x) {
        /* assuming `x` has 32 bits: lets count the low order 0 bits in batches */
        /* mask the 16 low order bits, add 16 and shift them out if they are all 0 */
        if (!(x & 0x0000FFFF)) { bits += 16; x >>= 16; }
        /* mask the 8 low order bits, add 8 and shift them out if they are all 0 */
        if (!(x & 0x000000FF)) { bits +=  8; x >>=  8; }
        /* mask the 4 low order bits, add 4 and shift them out if they are all 0 */
        if (!(x & 0x0000000F)) { bits +=  4; x >>=  4; }
        /* mask the 2 low order bits, add 2 and shift them out if they are all 0 */
        if (!(x & 0x00000003)) { bits +=  2; x >>=  2; }
        /* mask the low order bit and add 1 if it is 0 */
        bits += (x & 1) ^ 1;
    }
    return bits;
}

using namespace std;

FILE *fin = fopen("kimbits.in", "r");

struct Bitstring {
	int n_ones, val;

	Bitstring(int n_ones, int val) {
		this->n_ones = n_ones;
		this->val = val;
	}
};

int N, L; 
long long I;

vector<Bitstring> v;

// int trail(string s, char c) {
// 	int l = s.length(), count = 0;
// 	for (int i = l - 1; i >= 0; --i) {
// 		// cout << "i: " << i << endl;
// 		if (s.at(i) == c) count++; 
// 		else break;
// 	}
// 	return count;
// }


// add's one at the end of the string
// this will be called ONLY if no rounding is needed
// i.e., the argument ends with 0

// string round(string s) {
// 	int trailingZeroes = trail(s, '0'); 
// 	string core = s.substr(0, s.length() - trailingZeroes);
// 	int t = trail(core, '1');
// 	// cout << "t: " << t << endl;
// 	string z1(t, '0');
// 	core = core.replace(core.end()-t, core.end(), z1);
// 	core.replace(core.end()-t-1, core.end()-t, "1");
// 	string z2(trailingZeroes, '0');
// 	return core + z2;
// }


Bitstring nextString(Bitstring b, int L) {
	string ns = "";
	if (!(b.val & 1)  && b.n_ones < L) {
		return Bitstring(b.n_ones + 1, b.val + 1);
	}
	// There's a trailing sequence of ones, or we have L ones.
	// in either case, we "round"
	// ns = round(b.s);
	if (b.val & 1) {
		// cout << b.n_ones << " " << trail(b.s, '1') << endl;
		return Bitstring(b.n_ones - trailing_ones(b.val) + 1, b.val + 1);
	}
	else {
		int tz = trailing_zeroes(b.val);
		int core = (int) b.val / pow(2, tz);
		int to = trailing_ones(core);
		core++;
		core *= pow(2, tz);
		// assert(core >= 0);
		return Bitstring(b.n_ones - to + 1, core);	
	}	
}

string padLeft(string s, int l) {
	while (s.length() < l) s = "0" + s;
	return s;
}

string toBin(int n, int l) {
	if (n == 0) return padLeft("0", l);
	string ans = "";
	while (n > 0) {
		if (n & 1) ans = "1" + ans;
		else ans = "0" + ans;
		n /= 2;
	}
	return padLeft(ans, l);
}

int main()
{
	ofstream fout ("kimbits.out");
	fscanf(fin, "%d %d %lld ", &N, &L, &I);	

	Bitstring b = Bitstring(0, 0);

	if (N == L) {
		fout << toBin(I - 1, N) << endl;
		return 0;
	}

	for (int i = 1; i < I; ++i) {
		b = nextString(b, L);
		// cout << b.val << endl;
	}
	fout << toBin(b.val, N) << endl;
	fout.close();
	// cout << toBin(2147483647, 31) << endl;
    return 0;
}

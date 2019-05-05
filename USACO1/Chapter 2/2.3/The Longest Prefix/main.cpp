/*
ID: andreww7
TASK: prefix
LANG: C++11
*/

/*
Observation: this is somewhat similar to the coin problem in that
you try to 'optimize' some sort of grouping of constituents to 
make some whole. This is exactly why a greedy solution is not guaranteed
to work. Playing around with the input a bit, 
you might come up with a test case that looks like: 

A AB BA CA BBC BBCAC BB CB
.
BBCACB

A greedy solution that takes the largest prefix that can fit in at any
point will immediately take BBCAC and then output 5. However, choosing BB, CA, then
CB would actually yield 6. 

Likewise, if a greedy solution took the smallest, the same would happen
in other cases: 

A B C CDE D
.
ABCDE

This greedy solution would take A, B, C, then D, but then stop. 
The optimal was A, B, then CDE.

Therefore, we process the string in order, maintaining a boolean array
that checks whether a prefix of a particular length can be formed from the constituents.
Then, we append the primitives to this "current prefix", and if it still
matches with the sequence, it is a better solution. 

At the end, we take the largest index in the boolean array whose value is true.

The following implementation of solve() runs in O(PS) where P is the number of 
primitives and S is the length of the sequence. PS <= 200 * 200000.

One possible bottleneck of the problem is checking string equality; keep in mind that using
this DP solution, every time a primitive is appended to an existing prefix of the sequence
(that is known to be "formable"), THAT portion of the sequence is the ONLY part of it that
will differ from this new candidate for a prefix. What this means is that
every time we add a primitive to some prefix of the sequence to test out if that also 
forms a prefix, examine *only* that part of the string; it is known that everything before
the primitive is already a prefix. Hence, this is why isMatch was implemented the way it was.
*/

#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <vector>

using namespace std; 

int best, L;
string sequence;
bitset<200011> canBeFormed; // 1-indexed
vector<string> primitive;

bool isMatch(string s, int i) { // return true if s is a prefix of sequence
	return s == sequence.substr(i, s.length());
}

int solve() {
	for (int i = 0; i < L; i++){
		// append to currentPrefix only if currentPrefix can be formed
		// unless you're just starting.
		if (canBeFormed[i] || i == 0) { 
			// if (i == 0) cout << "OK\n" << currentPrefix << endl;
			for (int j = 0; j < primitive.size(); j++) {
				if (isMatch(primitive[j], i)) {
					canBeFormed[i + primitive[j].length()] = 1;
				}
			}
		}
	}
	// return the highest index of "can be formed" that is true; else 0
	for (int i = L; i >= 0; i--)
		if (canBeFormed[i])
			return i;
	return 0;
}

int main() {
	ifstream fin ("prefix.in");
	ios::sync_with_stdio(0);
	cin.tie(0);
	// careful here, even though the number of 
	// primitives is at most 200, you still have
	// to input the ".", so upper bound the loop
	// at 201 iterations.
	for (int i = 0; i <= 200; i++){
		string s; 
		fin >> s; 
		if (s != ".")
			primitive.push_back(s);
		else 
			break;
	}
	while (!fin.eof()) {
		string subsequence; 
		fin >> subsequence; 
		sequence += subsequence; 
	}
	fin.close();
	L = sequence.length();

	best = solve();

	ofstream fout("prefix.out");
	fout << best << "\n";
	fout.close();
	return 0;
}
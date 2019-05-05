/* 
ID: andreww7
TASK: lamps
LANG: C++
*/

/*
The problem seems intractable with brute force: if you try every single
combination of button presses, then the upper bound on the problem size is 
4 ^ 10000 which is about 10 ^ 6020. Every single button press (of which
there are 10000) is a choice between four options. 

One powerful observation you can make is that the order of the button presses
is irrelevant. This is because the number of times that any particular
light will be toggled for any 'reordering' of the button presses
does not change. Then, the problem can be viewed as dividing slots: 

Let the following slots represent all button presses:

_ _ _ _ _ _ ... _ _ _ _

We will group the button presses into buckets: the first bucket contains
the presses of button 1, the second, of button 2, and so on. Notice that the 
buckets may very well be empty. If we visualize the delimiters of buckets as
vertical bars, then we are asking ourselves, "in how many ways can we place 
these bars?" For instance, if we have C = 8, the following might happen: 

|_ _ _ || _ _ _ | _ _

All the buttons to the left of a bar (and ONLY that bar) represent the
button presses of that bucket. Since the bars can go before and after the slots
for button presses at every point, there are C + 1 choices for each bar. 
As well, each bar can be chosen independently from the others.

Therefore, after making this observation, we only need to check at most
10001 ^ 4 combinations of button presses (about 10 ^ 16). Still, this is 
too much to pass in the time limit. 

One final observation that we can make is the fact that pressing any particular
button twice is the same as pressing it no times. Therefore, 
we care only whether each button was pressed an even number of times
or whether it was pressed an odd number of times (2 states for each button). 

This reduces the search space to just 4 ^ 2 = 16 combinations! An absolutely
brilliant simplification that will surely pass in the time. (Notice that 
this does not depend on C).

Corner case: what if C < 4?
*/

#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include <set>

using namespace std; 

int N, C; 
bitset<101> state;

int main() {
	ifstream fin("lamp.in");
	fin >> N >> C; 	

	state.set();

	bool end = false; 
	while (!end) {// turn the lamps on
		int k; 
		fin >> k; 
		cout << k << endl;
		if (k == -1) {
			end = true;
			break;
		}
		state[k] = 1;
	}

	end = false; 
	while (!end) {// turn the lamps off
		int k; 
		fin >> k; 
		if (k == -1) {
			end = true;
			break;
		}
		state[k] = 1;
	}

	for (int i = 1; i <= N; i++) {
		cout << state[i] << " ";
	}
	cout << endl;
	return 0;
}













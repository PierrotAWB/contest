#include <iostream>
#include <string> 
#include <algorithm>
#include <map>

using namespace std; 

int colour[6];
int L = 0;

int main() { 
	int N; 
	cin >> N;
	for (int i = 0; i < N; i++) { 
		string s; 
		cin >> s;
		if (s == "red") colour[0]++;
		if (s == "orange") colour[1]++;
		if (s == "yellow") colour[2]++;
		if (s == "green") colour[3]++;
		if (s == "blue") colour[4]++;
		if (s == "black") colour[5]++;
	}

	sort(colour, colour + 6); 
	reverse(colour, colour + 6);

	while (colour[1] != 0) { 
		int delta = colour[1];
		L += 2 * delta;
		colour[0] -= delta; 
		colour[1] -= delta; 
		sort(colour, colour + 6); 
		reverse(colour, colour + 6);
	}

	if (colour[0] > 0) L++;

	cout << L << endl;
	return 0;
}
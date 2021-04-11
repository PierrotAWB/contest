#include <iostream>
#include <string>

#define MAX 4294967295

using namespace std;

int n;
long long x = 0;

long long loop(long long i) {
	string s;
	long long d = 0;
	while (cin >> s) {
		if (s == "end") {
			if (x + i*d > MAX) {
				cout << "OVERFLOW!!!\n";
				exit(0);
			}
			return i * d;
		}
		else if (s == "add") d++;
		else {
			long long iterations;
			cin >> iterations;
			d += loop(iterations);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string instr;
		cin >> instr;
		if (instr == "add") x++;
		if (instr == "for") {
			long long iterations; 
			cin >> iterations;
			x += loop(iterations);
		}
	}	
	if (x > MAX) cout << "OVERFLOW!!!\n";
	else cout << x << "\n";	
	return 0;
}
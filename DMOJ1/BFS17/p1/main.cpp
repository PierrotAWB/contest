#include <iostream>
#include <string>
using namespace std; 

int main() { 
	int N; 
	cin >> N; 
	int nname = 0;
	for (int i = 0; i < N; i++) { 
		string s; 
		cin >> s; 
		if (s.length() <= 10) { 
			nname++;
		}
	}
	cout << nname << "\n";
	return 0;
}
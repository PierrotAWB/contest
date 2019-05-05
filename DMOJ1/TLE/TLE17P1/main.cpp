#include <iostream>
#include <string>

using namespace std; 

int main() { 
	string s; 
	getline(cin, s); 
	for (int i = 2; i < s.length() - 4; i++) {
		cout << "(c" << s.at(i) << "r ";
	}
	cout << "x";
	for (int i = 0; i < s.length() - 6; i++) { 
		cout << ")";
	}
	cout << endl;
	return 0;
}
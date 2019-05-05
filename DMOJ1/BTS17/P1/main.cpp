#include <iostream>
#include <string> 
#include <ctype.h>

using namespace std; 

string word[51];

int main() { 
	string s, a;
	int i = 0;
	while (cin >> s) { 
		word[i] = s; 
		i++;
	}
	for (int j = 0; j < i; j++) {
		cout << word[j];

		if (j == i - 1) {
			cout << ".";
		} else { 
			if (isupper(word[j+1][0])) { 
				cout << ".";
			}
			cout << " ";
		}
	}
	return 0;
}
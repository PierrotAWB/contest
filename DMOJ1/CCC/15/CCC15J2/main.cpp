#include <iostream>
#include <string>

using namespace std; 

int main() { 
	string s;
	short happy = 0, sad = 0;

	cin >> s; 
	for (int i = 0; i < s.length() - 3; i++) { 
		if (s.at(i) == ':' && s.at(i+1) == '-') { 
			if (s.at(i + 2) == '(') { 
				sad++;
			} else if (s.at(i + 2) == ')') { 
				happy++;
			} else { 
				;
			}
		}
	}

	cout << happy << " " << sad << endl;


	if (happy == 0 && sad == 0) {
		cout << "none" << endl;
	} else if (happy > sad) { 
		cout << "happy" << endl;
	} else if (happy < sad) { 
		cout << "sad" << endl;
	} else { 
		cout << "unsure" << endl;
	}
	return 0;
}
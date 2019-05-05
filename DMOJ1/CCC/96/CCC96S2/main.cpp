#include <iostream>
#include <string>

using namespace std; 

int absoluteVal(int n) { 
	if (n < 0) n *= -1;
	return n;
}

string subtract(string a, string b){

	if (a == b) return "0";
	
	int lenDiff = absoluteVal(a.length() - b.length());
	if (lenDiff != 0) {
		string zeroPad(lenDiff, '0');
		if (a.length() < b.length()) {
			a = zeroPad + a;
		} else {
			b = zeroPad + b;
		}
	}
	
	string answer = "";
	
		for (int i = a.length() - 1; i >= 0; i--) {
			int difference = (int) a.at(i) - (int) b.at(i);
			if (difference < 0) {
				difference += 10;
				a.at(i - 1) = (char) (int) a.at(i - 1) - 1;
			}
			answer = to_string(difference) + answer;
		}

	while (answer.at(0) == '0') answer.erase(0, 1);
	
	return answer;
}

int main() { 
	int T;
	cin >> T; 
	for (int i = 0; i < T; i++) { 
		string originalNumber; cin >> originalNumber; 
		string number = originalNumber;
		cout << number << endl;
		while (number.length() > 2) { 
			string unitDig = number.substr(number.length() - 1, 1);
			number.erase(number.length() - 1, 1); 
			number = subtract(number, unitDig);
			cout << number << endl;
		}
		int twoDig = stoi(number); 
		if (twoDig % 11 == 0) {
			cout << "The number " << originalNumber << " is divisible by 11." << endl;
		} else { 
			cout << "The number " << originalNumber << " is not divisible by 11." << endl;
		}
	}
	return 0;
}
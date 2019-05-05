#include <iostream>
using namespace std; 

char resp[20002];
char ans[20002];

int main() { 
	int N; 
	cin >> N; 
	for (int i = 0; i < N; i++) {
		cin >> resp[i];
	}

	for (int i = 0; i < N; i++) { 
		cin >> ans[i];
	}

	int correctCounter = 0;

	for (int i = 0; i < N; i++) {
		if (resp[i] == ans[i]) correctCounter++;
	}

	cout << correctCounter << endl;
	return 0;
}
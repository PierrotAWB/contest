#include <iostream>

using namespace std; 

int Se[100002];
int Sw[100002];
int N;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int k; 
		cin >> k;
		if (i == 1)
			Sw[1] = k;
		else 
			Sw[i] = Sw[i - 1] + k;
	}

	for (int i = 1; i <= N; i++) {
		int k; 
		cin >> k;
		if (i == 1)
			Se[1] = k;
		else 
			Se[i] = Se[i - 1] + k;
	}

	// find max K such that Se[k] == Sw[k]
	int lastDay = 0;
	for (int i = 1; i <= N; i++) { 
		if (Sw[i] == Se[i]) 
			lastDay = i;
	}

	cout << lastDay << "\n";

	return 0;
}
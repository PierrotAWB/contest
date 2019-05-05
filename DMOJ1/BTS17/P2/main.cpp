#include <iostream>

using namespace std; 

int main() { 
	short G;
	double probability = 1; 

	cin >> G;

	for (int i = 0; i < G; i++) { 
		int e, p; 
		cin >> e >> p; 
		probability *= (1 - (e / (double) p));
		if (probability == 0) { 
			cout << 0 << endl; 
			return 0;
		}
	}
	cout << probability << endl;
	return 0;
}
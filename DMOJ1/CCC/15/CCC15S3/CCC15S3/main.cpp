#include <iostream>
#include <set> 

using namespace std;

/// global var
set<int> emptyGates;
int G;

void initGates() {
	for (int i = 1; i <= G; i++) {
		emptyGates.insert(-1 * i);
	}
}

int main() {
	int P;
	cin >> G >> P;
	initGates();
	int g;
	for (int i = 0; i < P; i++) {
		cin >> g;
		if (emptyGates.lower_bound(-g) == emptyGates.end()){ // it cannot fit in gate
			cout << i;
			return 0; // terminate the process
		} else {
			emptyGates.erase(emptyGates.lower_bound(-g)); // remove the highest numbered gate
		}
	}
	cout << P; // every plane can land.
	return 0;
}

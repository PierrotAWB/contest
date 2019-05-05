#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std; 

const long long modulo = 1000000007;

long long plant[100]; // ith location holds /cost/ of ith plant
long long friendCost[100]; // the ith location holds how much the ith friend pays

long long cost = 0;

long long exponentiate (long long base, long long exponent) { 
	// assume exponent is integral
	long long result = 1; 
	for (int i = 0; i < exponent; i++) { 
		result = (result % modulo * base % modulo) % modulo;
	}
	return result % modulo;
}

int main() { 
	short n, m; 
	cin >> n >> m; 

	for (int i = 0; i < n; i++) { 
		cin >> plant[i];
	}

	sort(plant, plant + n); 
	reverse(plant, plant + n); // buy the most expensive plants as early as possible

	double numRounds = n / (double) m;

	for (int i = 0; i < numRounds; i++) { 
		for (int j = 0; j < m; j++) { 
			friendCost[j] = (long long) ((friendCost[j] % modulo + exponentiate(plant[i * m + j], i)) % modulo);
			if (friendCost[j] > 0) cout << friendCost[j] << endl;
			if (friendCost[j] < 0) cout << "OVERFLOW\n";
		}
	}

	for (int i = 0; i < n - numRounds * m; i++) { 
		friendCost[i] = (long long) ((friendCost[i] % modulo + exponentiate(plant[(int)numRounds * m + i], ceil(numRounds))) % modulo);
		if (friendCost[i] > 0) cout << friendCost[i] << endl;
		if (friendCost[i] < 0) cout << "OVERFLOW\n";
	}

	for (int i = 0; i < m; i++) { 
		cost = (cost % modulo + friendCost[i] % modulo) % modulo;
	}

	cout << cost << endl;
}
/*
ID: andreww7
TASK: combo
LANG: C++11
*/

#include <fstream>
#include <set>
#include <tuple>

#include <iostream>

using namespace std; 
set<tuple<int, int, int> > combo; 

void generatePossibleCombinations(tuple<int, int, int> combination, int N);
int mod(int m, int n); // customized mod so that 0 % m = m

int main() { 
	ifstream fin("combo.in");
	ofstream fout("combo.out");

	int N; // modulus of all operations
	fin >> N; 

	int f1, f2, f3, m1, m2, m3; 
	fin >> f1 >> f2 >> f3 >> m1 >> m2 >> m3;

	generatePossibleCombinations(make_tuple(f1, f2, f3), N); 
	generatePossibleCombinations(make_tuple(m1, m2, m3), N);

	// for (auto u : combo) { 
	// 	cout << get<0> (u) << " " << get<1> (u) << " " << get<2> (u) << endl;
	// }

	//cout << mod(-2, 4) << " " << mod(-1, 4) << " " << mod(0, 4) << endl;
	//cout << mod(6, 4) << " " << mod(5, 4) << " " << mod(4, 4) << endl;
	fout << combo.size() << "\n";

	return 0;
}

void generatePossibleCombinations(tuple<int, int, int> combination, int N){ 
	for (int i = -2; i <= 2; i++) { 
		for (int j = -2; j <= 2; j++) { 
			for (int k = -2; k <= 2; k++) { 
				combo.insert(make_tuple(mod(get<0>(combination) + i, N), mod(get<1>(combination) + j, N), mod(get<2>(combination) + k, N)));
				// if (mod(get<0>(combination) + i, N) == 0) cout << get<0>(combination) + i << " " << get<0>(combination) + j << " " << get<0>(combination) + k << endl;
			}
		}
	}
}

int mod(int m, int n) { 
	if (m % n == 0) return n;
	else if (m > 0) return m % n; 
	return m % n + n;
}

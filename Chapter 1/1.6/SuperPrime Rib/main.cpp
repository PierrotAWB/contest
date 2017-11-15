/*
ID: andreww7
TASK: sprime
LANG: C++11
*/

// The solution uses a BFS approach with an optimized primality test

#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

vector<set<int> > superprime;
int N;

bool isPrime(int N){
	if (N < 2) return false; 
	if (N == 2 || N == 3) return true; 
	if (N % 2 == 0) return false; 

	for (int i = 3; i * i <= N; i+=2) { 
		if (N % i == 0) return false;
	}
	return true;
}

void solve(int k) { 
	set<int> k_superprime = {};
	if (k == 0) { 
		for (int i = 1; i < 10; i++) { 
			if (isPrime(i))
				k_superprime.insert(i);
		}
		superprime.push_back(k_superprime);
		return;
	}

	for (auto u : superprime[k - 1]) { 
		int sp;
		for (int digit = 1; digit <= 9; digit+=2) { 
			sp = 10 * u + digit;

			if (isPrime(sp)) { 
				k_superprime.insert(sp);
			}
		}
	}
	superprime.push_back(k_superprime);
}

int main() { 
	ifstream fin("sprime.in");
	fin >> N; 
	fin.close(); 

	for (int i = 0; i < N; i++) { 
		solve(i); // superprimes of length N are stored in superprime[N - 1]
	}

	ofstream fout("sprime.out");
	for (auto u : superprime[N - 1]) 
		fout << u << "\n";
	fout.close();

	return 0;
}
/* 
TASK: money
LANG: C++11
*/
#include <fstream>
#include <math.h>
using namespace std;
long long denom[25];
long long ways[10001];
int main() {
	ifstream fin("money.in");
	long long V;
	int N; 
	fin >> V >> N;
	for (int i = 0; i < V; i++) {
		fin >> denom[i];
	}
	fin.close();
	// if the amount is equal to one of the coins, 
	// increment the number of ways to form that amount by one
	ways[0] = 1;
	for (int i = 0; i < V; i++)
		for (int j = denom[i]; j <= N; j++)
			ways[j] += ways[j - denom[i]];
	ofstream fout("money.out");
	fout << ways[N] << "\n";
	fout.close();
	return 0;
}
/* 
ID: andreww7
TASK: skidesign
LANG: C++11
*/

#include <fstream>
#include <vector>

using namespace std;

#define INF 2000000000;

vector <int> hill;

int main() { 
	ifstream fin ("skidesign.in");
	ofstream fout ("skidesign.out");
	int N; 
	fin >> N; 
	for (int i = 0; i < N; i++) { 
		int k; 
		fin >> k; 
		hill.push_back(k);
	}
	int minCost = INF;
	for (int i = 0; i <= 83; i++) { // find the best interval
		int TempCost = 0;
		for (int j = 0; j < N; j++) { 
			if (hill[j] < i) { 
				TempCost += (i - hill[j]) * (i - hill[j]);
			} else if (hill[j] > i + 17) { 
				TempCost += (hill[j] - i - 17) * (hill[j] - i - 17);
			}
		}
		if (TempCost < minCost) minCost = TempCost;
	}
	fout << minCost << "\n";
	return 0;
}
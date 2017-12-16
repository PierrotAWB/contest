#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>

using namespace std; 

int N; 
int grade[100001];
double avg[100001]; // stores average from index i to end
set<int> bestK;

int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);

	ifstream fin ("homework.in");
	fin >> N;
	for (int i = 1; i <= N; i++) { 
		fin >> grade[i];
	}	
	fin.close();

	int lowestGrade = grade[N];
	int sum = grade[N]; // start with the last element
	for (int i = 2; i <= N - 1; i++) {	// add in elements from right and calc average
		int j = N - i + 1;
		lowestGrade = min(grade[j], lowestGrade);

		sum += grade[j];
		double average = (sum - lowestGrade) / (double) (i - 1);
		avg[j] = average;
	}

	double currentMaxAverage = -1000;
	for (int i = 1; i <= N; i++) {
		if (avg[i] == currentMaxAverage) {
			bestK.insert(i - 1);
		}
		if (avg[i] > currentMaxAverage) { 
			currentMaxAverage = avg[i];
			bestK.clear();
			bestK.insert(i - 1);
		}
	} 

	for (int i = 0; i <= N; i++) {
		cout << avg[i] << endl;
	}

	ofstream fout ("homework.out");
	for (auto u : bestK)
		fout << u << "\n";
	fout.close();

	return 0;
}
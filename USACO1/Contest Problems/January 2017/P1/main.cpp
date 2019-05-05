#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

int N, T, ans;
vector<int> d;

bool isPossible(int K) {
	int time = 0;
	priority_queue<int, vector<int>, greater<int> > q;
	for (int i = 0; i < N; i++) {
		if (q.size() == K){
			time = q.top();
			q.pop();
			// if (K == 3) cout << q.top() << " " << endl;
		}
		if (time + d[i] > T) 
			return false; 
		q.push(d[i] + time);
	}
	return true;
}

int main() {
	ifstream fin ("cowdance.in");
	fin >> N >> T; 
	for (int i = 0; i < N; i++) {
		int k; 
		fin >> k; 
		d.push_back(k);
	}
	fin.close();
	int a = 1, b = N; 
	while (a != b) {
		int c = (a + b) / 2;
		if (isPossible(c)) {
			b = c;
		} else {
			a = c + 1;
		}
	}
	ofstream fout("cowdance.out");
	fout << a << "\n";
	fout.close();
	return 0;
}
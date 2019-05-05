/* 
ID: andreww7
TASK: runround
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <set>

using namespace std;

int M, L;
string ans = "";
bitset<10> used;

bool isRunAround(string current, int length) {
	if (stoi(current) <= M) return false; 
	
	set<int> digitSet;
	for (int i = 0; i < length; i++) {
		digitSet.insert(stoi(current.substr(i, 1)));
	}

	int currentDig = stoi(current.substr(0,1)), currentPos = 0;

	digitSet.erase(digitSet.find(currentDig));

	for (int i = 0; i < length - 1; i++) {
		int shift = currentDig % length;
		currentPos = (currentPos + shift) % length;
		currentDig = stoi(current.substr(currentPos, 1));

		if (digitSet.find(currentDig) == digitSet.end()) {
			return false;
		}

		digitSet.erase(digitSet.find(currentDig));
	}	

	int shift = currentDig % length;
	currentPos = (currentPos + shift) % length;
	currentDig = stoi(current.substr(currentPos, 1));

	if (currentDig == stoi(current.substr(0, 1))) return true;

	return false;
}

void generateCandidate(string current, int digitCount, int length){
	if (ans != "") 
		return;

	if (digitCount == length) {
		if (isRunAround(current, length)) {
			ans = current;
		}
		return;
	}

	for (int i = 1; i <= 9; i++) {
		if (used[i] == 0) {
			used[i] = 1;
			generateCandidate(current + to_string(i), digitCount + 1, length);
			used[i] = 0;
		}
	}
}

void solve() {
	string s = to_string(M);
	int fd = stoi(s.substr(0, 1));

	L = s.length();

	// answers of same length
	for (int i = fd; i <= 9; i++) {
		used[i] = 1;
		generateCandidate(to_string(i), 1, L);
		if (ans != "") return;
		used[i] = 0;
	}

	// answers of greater length
	for (int i = L + 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++){
			used[j] = 1;
			generateCandidate(to_string(j), 1, i);
			if (ans != "") return;
			used[j] = 0;
		}
	}
}

int main() {
	ifstream fin("runround.in");
	fin >> M; 
	fin.close(); 

	solve();

	ofstream fout("runround.out");
	fout << ans << "\n";
	fout.close();
	return 0;
}
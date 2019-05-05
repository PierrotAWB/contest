#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

#define N 10
#define TARGET_LENGTH 16

using namespace std;

bool flag[N + 1];
vector<string> permutations;
vector<string> successful;

void permute(int k, string s);
string concat(int arr[]);
void solve(string s);
bool isSuccessful(int arr[]);

void permute(int k, string s) {
	if (k == 0) {
		// append one space for convenience in the parse method ("solve")
		permutations.push_back(s);
	}
	for (int i = 1; i <= N; i++){
		if (flag[i] == 0) {
			flag[i] = 1;
			permute(k - 1, s + to_string(i));
			flag[i] = 0;
		}
	} 
}

void solve(string s) {
	int node[N], index = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) == '1') {
			if (i < s.length() - 1) {
				// there's a chance you could be dealing with "10" and not "1"
				if (s.at(i + 1) == '0') {
					node[index] = stoi(s.substr(i, 2));
					i++;
				}
				else {
					node[index] = stoi(s.substr(i, 1));
				}
			} else {
				node[index] = stoi(s.substr(i, 1));
			}
		} else node[index] = stoi(s.substr(i, 1));
		index++;
	}
	if (isSuccessful(node)){
		string ans = concat(node); 
		if (ans.length() == TARGET_LENGTH){
			successful.push_back(ans);
		}
	}
}

string concat(int arr[]) {
	// find the smallest element on the outer ring
	int minimum = N + 1, index;
	for (int i = 0; i < N / 2 - 1; i++) {
		if (arr[i] < minimum) {
			minimum = arr[i];
			index = i;
		}
	}
	// concatenate in clockwise fashion around outer ring
	string ans = "";
	for (int i = 0; i < N / 2; i++) {
		int root = (index + i) % (N / 2);
		ans += to_string(arr[root]) + to_string(arr[root + N / 2]);
		if (root == N / 2 - 1) ans += to_string(arr[N / 2]);
		else ans += to_string(arr[root + N / 2 + 1]);
	}
	return ans;
}

bool isSuccessful(int arr[]) {
	int target = arr[0] + arr[N / 2] + arr[N / 2 + 1];
	// if (target == 9 and arr[0] == 4 and arr[1] == 5) {
	// 	for (int i = 0; i < N; i++) {
	// 		cout << arr[i] << " ";
	// 	}
	// 	cout << endl;
	// }
	for (int i = 1; i < N / 2 - 1; i++)
		if (arr[i] + arr[i + N / 2] + arr[i + N / 2 + 1] != target) return false; 
	if (arr[N / 2 - 1] + arr[N / 2] + arr[N - 1] != target) return false;
	return true;
}


int main() {
	permute(N, "");
	for (auto u : permutations) solve(u);
	sort(successful.rbegin(), successful.rend());
	for (auto u : successful) cout << u << endl;
	return 0;
}
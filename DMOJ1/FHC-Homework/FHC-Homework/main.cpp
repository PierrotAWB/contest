#include <iostream>
#include <bitset>
#include <vector>
#include <set>
using namespace std;

bitset<10000001> candidate;
vector<int> prime;

void findPrimes() {
	for (int i = 2; i < candidate.size(); i++) {
		candidate[i] = candidate[i]|1;
	}
	
	for (int i = 2; i < candidate.size(); i++) {
		if (candidate[i]) {
			for (int j = 2; j <= candidate.size() / i; j++) {
				candidate[i * j] = candidate[i * j]&0;
			}
		}
	}
	
	for (int i = 2; i < candidate.size(); i++) {
		if (candidate[i]) prime.push_back(i);
	}
}

int countPrimeDivisors(int N) { // maybe change out the set to optimize
	set<int> primeDivisor;
	for (int i = 0; i < prime.size(); i++) {
		if (N % prime[i] == 0) {
			primeDivisor.insert(prime[i]);
			while (N % prime[i]) N /= prime[i];
		}
		if (prime[i] > N) break;
	}
	if (primeDivisor.size() == 0) primeDivisor.insert(N);
	return primeDivisor.size();
}

int countK (int A, int B, int K) {
	int counter = 0;
	for (int i = A; i <= B; i++) {
		if ((i - A) % 10000 == 0) cout << i << endl;
		if (countPrimeDivisors(i) == K) counter ++;
	}
	return counter;
}

int main(int argc, const char * argv[]) {
	int T;
	cin >> T;
	
	findPrimes();
	
	for (int i = 0; i < T; i++) {
		int A, B, K;
		cin >> A >> B >> K;
		
		cout << "Case #" << i + 1 << ": " << countK(A, B, K) << endl;
		
	}
	return 0;
}

#include <iostream>
#include <vector>

using namespace std; 

int N, Q, total = 0;
vector<unsigned int> cumsum; 

int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N; 
	for (int i = 0; i < N; i++) { 
		int m; 
		cin >> m;
		total += m;
		cumsum.push_back(total);
	}
	cin >> Q; 
	for (auto u : cumsum) 
		cout << u << " ";


	for (int i = 0; i < Q; i++) { 
		int a, b;
		cin >> a >> b; 
		if (a != 0)
			cout << cumsum[b] - cumsum[a - 1] << "\n";
		else 
			cout << cumsum[b] << "\n";
	}
}

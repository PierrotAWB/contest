#include <iostream>
#include <bitset>
#include <vector>

using namespace std; 

int N; 
bitset<100001> tower1;
vector<int> moveList;

void toggle(int index) { 
	if (index == N) { 
		tower[N-1] = !tower[N-1];
		tower[N-2] = !tower[N-2];
		return;
	}
	switch (index) { 
		case 0 : tower[0] = !tower[0];
				 tower[1] = !tower[1];
				 break;
		default : 
				 tower[index] = !tower[index];
				 tower[index - 1] = !tower[index - 1];
				 tower[index + 1] = !tower[index + 1];
				 break;
	}
}

int main() { 
	cin >> N; 
	for (int i = 0; i < N; i++) { 
		short k; 
		cin >> k;
		tower[i] = k;
	}

	if (tower[0] == 0) {
		for (int i = 0; i < N - 1; i++) { 
				if (tower[i] != 0) { 
			if (i != 0) {
					toggle(i + 1);
					moveList.push_back(i + 1);
			}
		}
		cout << moveList.size() << "\n";
		for (auto u : moveList) { 
			cout << u + 1 << "\n";
	}

	} else { // direct toggle tower[0] or no?
		bitset<100001> tower2 (tower);
		vector<int> moveList2;

		// toggle 1
		toggle()

	}
	return 0;
}
#include <iostream>
#include <vector>
using namespace std; 

vector<pair<int, int> > target[1000000]; // each vector stores: (day, position)

int main() { 
	int N, Q, day = 0;
	cin >> N;
	for (int i = 0; i < N; i++) { 
		int pos; 
		cin >> pos;
		target[i].push_back(make_pair(0, pos));
	}
	cin >> Q; 
	for (int i = 0; i < Q; i++) { 
		char query; 
		cin >> query; 
		int x, y; 
		cin >> x >> y;
		x -= 1; 
		if (query == 'C') { 
			day++;
			target[x].push_back(make_pair(day, y));
		} else { 
			if (target[x][target[x].size() - 1].first <= day) {
				cout << target[x][target[x].size() - 1].second << endl;
				//cout << "OK" << endl;
			} else {
				for (int i = 0; i < target[x].size() - 1; i++) {
					if (target[x][i].first <= day && target[x][i + 1].first > day) { 
						cout << target[x][i].second << endl;
					}
				}
			}
		}
	}
	return 0;
}
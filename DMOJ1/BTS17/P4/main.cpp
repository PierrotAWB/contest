#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std; 

vector<pair<int, int> > dryTime;
bitset<10001> isDry;

bool cmp(pair<int, int> p, pair<int, int> q) { 
	return p.second < q.second;
}

int main() {
	int N, M, J, index = 0, timeCount = 0; 
	cin >> N >> M >> J; 

	// extreme cases
	if (J == 0 && M!= 0) { 
		cout << -1 << endl;
		return 0;
	}
	if (J > N) { 
		cout << 0 << endl; 
		return 0;
	}

	for (int i = 0; i < M; i++) { 
		int p, t; 
		cin >> p >> t; 
		dryTime.push_back(make_pair(p, t));
	}
	
	// sort in order of occurence
	sort(dryTime.begin(), dryTime.end(), cmp);

	for (int i = 0; i < M; i++) {
		isDry[dryTime[i].first] = 1; // spot is now available
		
		if (dryTime[i].first > index) {
			if (dryTime[i].first - index <= J) { 
				// if reachable, then jump
				int delta = dryTime[i].first - index;
				index += delta;
				timeCount = max(timeCount, dryTime[i].second);
			}
		}
		if (index == N) { 
			cout << timeCount << endl;
			return 0;
		}
		i++;
	}
	cout << -1 << endl;
	return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

bool cmp(pair<int, float> p, pair<int, float> q) { 
	return p.first > q.first; // guaranteed to be different
}

int main() {
	int N, x; 
	vector<pair<int, float> > score;

	cin >> N; 

	for (int i = 0; i < N; i++) { 
		unsigned int points;
		float avgRank; 
		cin >> points >> avgRank;
		score.push_back(make_pair(points, avgRank));
	}

	sort(score.begin(), score.end(), cmp);

	cin >> x;

	int i = 0;
	long long H = 1, L;
	while (score[i].first >= x) { 
		L = (2 * (long long) score[i].second - 1 + pow( pow(1 - 2 * (long long) score[i].second, 2) - 4 * (-1 * pow(H, 2) + H + 2 * (long long) score[i].second * H - 2 * (long long) score[i].second), 0.5)) / 2;
		//cout << L << " " << endl;
		H = L + !(score[i].first == x);
		i++;
	}
	cout << H << endl << L;
	return 0;

}


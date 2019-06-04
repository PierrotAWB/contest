#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int n, a[100001];
priority_queue<pair<int, int> > even, odd;

int main() {
	cin >> n;
	bool allSameParity = true;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if ((a[i] - a[0])&1) allSameParity = false;
	}
	if (allSameParity) {
		for (int i = 0; i < n; ++i) {
			cout << a[i] << " ";
		}
		return 0;
	}
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	return 0;
}
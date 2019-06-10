#include <iostream>

using namespace std;

int t, a[200001];

int binSearch(int low, int high, int target) {
	if (low == high) {
		return low;
	}
	else if (low + 1 == high) {
		return low;
	}
	int mid = (low + high)/2;
	if (mid > target) return binSearch(low, mid, target);
	return binSearch(mid, high, target);
}

int main() {
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, k, acc = 0;
		cin >> n >> k;
		for (int j = 0; j < n; ++j) {
			cin >> a[j];
			acc += a[j];
		}
		int avg = (int) (acc / (double) n);
		int ind = binSearch(0, n - 1, avg);	
		int l = ind, h = ind + 1;
		for (int j = 0; j < k; ++j) {
			if (a[ind] - a[l] < a[h] - a[ind]) {
				if (l > 0) l--;
				else h++;
			} else {
				if (h < n - 1) h++;
				else l--;
			}
		}
		cout << a[ind] - a[l] << "\n";
	}
	return 0;
}
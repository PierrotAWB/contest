/**
 *    author: awb29
 *    created: Fri Apr 30 05:04:27 PM EDT 2021 
 **/

#include <bits/stdc++.h>
using namespace std;

char reflectChar(char c) {
	switch (c) {
		case '0': 
		case '1': 
		case '8': return c;
		case '2': return '5';
		case '5': return '2';
		default:
				  return ' ';
	}
}

bool isValid(int x) {
	string sx;
	if (x == 0) return true;
	while (x > 0) {
		int d = x % 10;
		sx = to_string(d) + sx;
		x /= 10;
	}
	for (auto u : sx) {
		if (reflectChar(u) < '0') return false;
	}
	return true;
}


pair<int, int> reflect(int H, int M) {
	// Can't reflect
	if (!(isValid(H) && isValid(M)))
		return make_pair(-1, -1);

	string hour, minute;
	if (H < 10) hour = "0" + to_string(H);
	else hour = to_string(H);

	if (M < 10) minute = "0" + to_string(M);
	else minute = to_string(M);

	swap(hour[0], hour[1]);
	swap(minute[0], minute[1]);

	string T = minute + hour;
	for (int i = 0; i < (int) T.length(); ++i) T[i] = reflectChar(T[i]);
	int rhour, rminute;

	rhour = stoi(T.substr(0, 2));
	rminute = stoi(T.substr(2, 2));
	return make_pair(rhour, rminute);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int h, m;
		cin >> h >> m;
		int HH, MM;
		scanf("%d:%d", &HH, &MM);

		//  		printf("DEBUG HH MM: %d %d\n", HH, MM);
		// Only digits which CAN produce valid reflections are 
		// 0, 1, 2, 5, and 8

		int t = HH * m + MM;
		while (1) {
			int hr = t / m;	
			int min = t % m;
			auto R = reflect(hr, min);
			if (R.first < 0) {
				t = (t + 1) % (h * m);
				continue;
			}

			if (R.first < h && R.second < m) {
				cout << std::string(2 - to_string(hr).length(), '0')
					<< hr
					<< ":"
					<< std::string(2 - to_string(min).length(), '0')
					<< min
					<< '\n';
				break;
			}

			t = (t + 1) % (h * m);
		}
	}
}

/**
 *    author: awb29
 *    created: Thu Apr 15 20:24:23 EDT 2021
**/

#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sze;

int find_set(int v) {
	if (parent[v] == v)
		return v;
	return parent[v] = find_set(parent[v]);
}

int main() {
	ios::sync_with_stdio(false);	
	cin.tie(0);
	int n, m, ki, first, other;
	cin >> n >> m;

	parent.reserve(n + 1);
	sze.reserve(n + 1);

	auto make_set = [&](int v) {
		parent[v] = v;
		sze[v] = 1;
	};

	auto union_sets = [&](int a, int b) {
		a = find_set(a);
		b = find_set(b);
		if (a != b) {
			if (sze[a] < sze[b])
				swap(a, b);
			parent[b] = a;
			sze[a] += sze[b];
		}
	};

	for (int i = 1; i <= n; ++i) make_set(i);

	for (int i = 0; i < m; ++i) {
		cin >> ki;
		if (ki == 0) continue;
		cin >> first;
		for (int j = 0; j < ki - 1; ++j) {
			cin >> other;
			union_sets(first, other);
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		if (i != 1) {
			cout << " ";
		}
		cout << sze[find_set(i)];
	}
	cout << '\n';
}

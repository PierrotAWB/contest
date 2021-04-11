#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	if (!m) 
		cout << 1 << endl;
	else
		cout << min(m, n - m) << endl;
	return 0;
}

#include <iostream>

using namespace std; 

const short N = 100;
int p[N + 1]; // store p(n) at index n

int main() {
	p[1] = 0; p[2] = 1;
	for (int i = 3; i <= N; i++)
		for (int j = 1; j < i; j++)
			p[i] += p[i - j];
	cout << p[N] << endl;
	return 0;
}

/*
p(2) = 1
p(3) = 2
p(4) = 4
p(5) = 6
p(6) = 10

6

5, 1
4, 2
4, 1, 1
3, 3
3, 2, 1
3, 1, 1, 1
2, 2, 2
2, 2, 1, 1 
2, 1, 1, 1, 1
1, 1, 1, 1, 1, 1

*/
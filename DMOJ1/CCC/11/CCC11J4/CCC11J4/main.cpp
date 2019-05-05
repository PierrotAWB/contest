//
//  main.cpp
//  CCC11J4
//
//  Created by Andrew Wang on 2017-07-20.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

bool visited[201][401]; // coordinate array
pair<int, int> currentPosition = {-1, 0}; // current coordinate

int x(int coord) { // r
	return -coord;
}

int y(int coord) { // c
	return coord + 201;
}

void boreInit(char directive, unsigned int dist) { // silent function
	visited[x(currentPosition.first)][y(currentPosition.second)] = true;
	switch(directive){
		case 'd':
			for (int i = 1; i < dist; i++) {
				visited[x(currentPosition.first) + i][y(currentPosition.second)] = true;
			}
			currentPosition.first -= dist - 1;
			break;
		case 'u':
			for (int i = 1; i < dist; i++) {
				visited[x(currentPosition.first) - i][y(currentPosition.second)] = true;
			}
			currentPosition.first += dist - 1;
			break;
		case 'r':
			for (int i = 1; i < dist; i++) {
				visited[x(currentPosition.first)][y(currentPosition.second) + i] = true;
			}
			currentPosition.second += dist - 1;
			break;
		case 'l':
			for (int i = 1; i < dist; i++) {
				visited[x(currentPosition.first)][y(currentPosition.second) - i] = true;
			}
			currentPosition.second -= dist - 1;
			break;
	}
}

void wellInit() {
	boreInit('d', 3);
	boreInit('r', 4);
	boreInit('d', 3);
	boreInit('r', 3);
	boreInit('u', 3);
	boreInit('r', 3);
	boreInit('d', 5);
	boreInit('l', 9);
	boreInit('u', 3);
}

bool bore(char directive, unsigned int dist) { // return whether safe
	bool safe = true;
	string status;
	switch(directive){
		case 'd':
			for (int i = 1; i <= dist; i++) {
				if (visited[x(currentPosition.first) + i][y(currentPosition.second)] == true){
					safe = false;
					break;
				};
				visited[x(currentPosition.first) + i][y(currentPosition.second)] = true;
			}
			currentPosition.first -= dist;
			break;
		case 'u':
			for (int i = 1; i <= dist; i++) {
				if (visited[x(currentPosition.first) - i][y(currentPosition.second)] == true){
					safe = false;
					break;
				};
				visited[x(currentPosition.first) - i][y(currentPosition.second)] = true;
			}
			currentPosition.first += dist;
			break;
		case 'r':
			for (int i = 1; i <= dist; i++) {
				if (visited[x(currentPosition.first)][y(currentPosition.second) + i] == true){
					safe = false;
					break;
				};
				visited[x(currentPosition.first)][y(currentPosition.second) + i] = true;
			}
			currentPosition.second += dist;
			break;
		case 'l':
			for (int i = 1; i <= dist; i++) {
				if (visited[x(currentPosition.first)][y(currentPosition.second) - i] == true){
					safe = false;
					break;
				};
				visited[x(currentPosition.first)][y(currentPosition.second) - i] = true;
			}
			currentPosition.second -= dist;
			break;
	}
	
	if (safe) status = "safe";
	else status = "DANGER";
	
	cout << currentPosition.second << " " << currentPosition.first << " " << status << endl;
	return safe;
}

int main(int argc, const char * argv[]) {
	
	wellInit();
	
	char directive;
	unsigned int dist;
	
	while (cin >> directive) {
		if (directive == 'q') break;
		cin >> dist;
		bool safe = bore(directive, dist);
		if (!safe) break;
	}
	
	return 0;
}

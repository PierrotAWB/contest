#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std; 
int N; 
vector<tuple<int, string, string> > journal;
vector<string> winner[101]; // store the winners of the ith day at index i
int currentStatus[3] {7, 7, 7}; // Bessie at 0, Elsie at 1, Mildred at 2

bool comp(tuple<int, string, string> a, tuple<int, string, string> b) {
	return get<0> (a) < get<0> (b);
}

vector<string> determineWinner(int status[], int size) { 
	vector<string> winnerList;

	// determine the max production
	int maxProd = -10000; 
	for (int i = 0; i < size; i++) { 
		if (status[i] > maxProd) 
			maxProd = status[i];
	}
	
	if (status[0] == maxProd)
		winnerList.push_back("Bessie");
	if (status[1] == maxProd) 
		winnerList.push_back("Elsie");
	if (status[2] == maxProd) 
		winnerList.push_back("Mildred");

	return winnerList;
}

void update(string name, string delta) { 
	bool shouldAdd; 
	if (delta.at(0) == '+') 
		shouldAdd = true;
	else 
		shouldAdd = false;

	int change = stoi(delta.substr(1, delta.length() - 1));

	if (name == "Bessie"){	
		if (shouldAdd) 
			currentStatus[0] += change;
		else 
			currentStatus[0] -= change;	
	} else if (name == "Elsie"){ 	
		if (shouldAdd) 
			currentStatus[1] += change;
		else 
			currentStatus[1] -= change;
	} else {	
		if (shouldAdd) 
			currentStatus[2] += change;
		else 
			currentStatus[2] -= change;
	}
}	

int main() {
	ifstream fin("measurement.in");
	fin >> N; 
	for (int i = 0; i < N; i++) { 
		int day; 
		string name, delta; 
		fin >> day >> name >> delta;
		journal.push_back(make_tuple(day, name, delta));
	}
	fin.close();

	// sort in chronological order
	sort(journal.begin(), journal.end(), comp);

	// for (auto u : currentStatus) 
	// 	cout << u << " ";
	// cout << endl;

	winner[0] = determineWinner(currentStatus, 3);

	int logIndex = 0;	
	// go through the days and update winners
	for (int i = 1; i <= 100; i++) { 
		// process the logs 
		while (get<0> (journal[logIndex]) == i) { 
			string name = get<1> (journal[logIndex]), delta = get<2> (journal[logIndex]);
			update(name, delta); // fixes the current Status
			logIndex++;
		}
		// find the winners and push to winner array
		// for (auto u : currentStatus) { 
		// 	cout << u << " ";
		// }
		// cout << endl;
		winner[i] = determineWinner(currentStatus, 3);
	}

	// process winner array with change counter
	int changeCounter = 0; 
	for (int i = 1; i <= 100; i++) { 
		if (winner[i] != winner[i - 1]) 
			changeCounter++;
	}

	ofstream fout("measurement.out");
	fout << changeCounter << "\n";
	fout.close();

	return 0;
}


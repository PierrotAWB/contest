#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <deque>
#include <algorithm>
#include <set>
#include <map>

using namespace std; 

int N, G, maxProd = -1;

int displayChangeCounter = 0;

deque<tuple<int, int, string> > entry; 
set<int> pLevel; 
map<int, int> production;

set<int> winner;

bool comp(tuple<int, int, string> a, tuple<int, int, string> b);
void processEntry(int, int, string);
set<int> trackChange();
void updateMaxProd(); 

int main() {
	ifstream fin("measurement.in");
	fin >> N >> G;
	for (int i = 0; i < N; i++) {
		int day, id; 
		string delta; 
		fin >> day >> id >> delta;
		production[id] = G;
		winner.insert(id);
		entry.push_back(make_tuple(day, id, delta));
	}
	fin.close();

	production[-2] = G; // represents any cows that aren't mentioned in the logs
	winner.insert(-2);

	sort(entry.begin(), entry.end(), comp);
	pLevel.insert(G);

	// process the entries on a per-day basis; then track changes to winners
	while (!entry.empty()) {
		auto logEntry = entry.front(); // marks the start of a new day
		int i = 0, currentDay = get<0> (logEntry);
		while (get<0> (entry[i]) == currentDay) {
			// cout << i << " " << currentDay << endl;
			int day = get<0> (entry[i]), id = get<1> (entry[i]);
			string delta = get<2> (entry[i]);
			processEntry(day, id, delta);
			updateMaxProd();
			i++;
		}
		if (winner != trackChange()) {
			displayChangeCounter++;
			winner = trackChange();
		}
		for (int j = 0; j < i; j++)
			entry.pop_front(); // pop as many logs off as were processed
	}

	// for (auto u : entry) {
	// 	cout << get<0> (u) << " " << get<1> (u) << " " << get<2> (u) << "\n";
	// }

	ofstream fout("measurement.out");
	fout << displayChangeCounter << "\n";
	fout.close();

	return 0;
}

bool comp(tuple<int, int, string> a, tuple<int, int, string> b) {
	// sort by day number
	return get<0> (a) < get<0> (b);
}

void processEntry(int day, int id, string delta) {
	bool shouldAdd; 
	int change = stoi(delta.substr(1, delta.length() - 1));
	switch (delta.at(0)) {
		case '+': shouldAdd = 1;
				  break;
		default: 
				  shouldAdd = 0;
	}

	if (shouldAdd)
		production[id] += change; 
	else {
		int temp = production[id];
		bool newMaxNeeded = true;
		production[id] -= change;
		// check to see if the max has changed

		for (auto u : production)
			if (u.second == temp) {
				newMaxNeeded = false;
				break;
			}

		if (newMaxNeeded) {
			pLevel.erase(temp);
		}
	}


	if (pLevel.find(production[id]) == pLevel.end()) // new production formed; insert it
		pLevel.insert(production[id]);
}

set<int> trackChange() {
	set<int> currentWinner;

	for (auto u : production)
		if (u.second == maxProd)
			currentWinner.insert(u.first);

	return currentWinner;
}

void updateMaxProd() {
	auto it = pLevel.end(); 
	it--;
	maxProd = *it;
}

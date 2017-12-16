#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int N, G, changeCounter = 0;
vector<tuple<int, int, string> > journal;
map<int, int> currentProduction;
set<int> winnerSet;

bool comp(tuple<int, int, string> a, tuple<int, int, string> b) {
	return get<0> (a) < get<0> (b);
}	

void update(int name, string delta);
set<int> determineWinners();
void updateWinners();

int main() {
	
	ifstream fin("measurement.in");
	fin >> N >> G; 

	for (int i = 0; i < N; i++) { 
		int day, name;
		string delta; 
		fin >> day >> name >> delta;
		winnerSet.insert(name);
		currentProduction[name] = G;
		journal.push_back(make_tuple(day, name, delta));
	}
	fin.close();

	currentProduction[-2] = G; // represents the OTHER cows; if all else fall below G, this cow wins

	// sort in chronological order
	sort(journal.begin(), journal.end(), comp);

						// for (auto u : journal) 
						// 	cout << get<0> (u) << " " << get<1> (u) << " " << get<2> (u) << endl;

						// for (auto u : currentProduction) 
						// 	cout << u.first << " " << u.second << endl;

	int currentDay = get<0> (journal[0]);
	int logIndex = 0;

	for (int i = 0; i < N; i++) {
		// cout << "current day: " << currentDay << " " << endl;
		while (get<0> (journal[logIndex]) == currentDay) {
			// process all the entries in that day
			// process and update for the ith entry in journal
			int name = get<1> (journal[i]);
			string delta = get<2> (journal[i]);
			update(name, delta);
			
			logIndex++;
		}	
		i = logIndex - 1;
		currentDay = get<0> (journal[logIndex]);
		if (determineWinners() != winnerSet) {
			changeCounter++;
			updateWinners();
		}
		// cout << "#Logs: " << logIndex << endl;
	}

	ofstream fout("measurement.out");
	fout << changeCounter << "\n";
	fout.close();

	return 0;
}

void update(int name, string delta) { 
	bool shouldAdd; 
	if (delta.at(0) == '+') 
		shouldAdd = true;
	else 
		shouldAdd = false;

	int change = stoi(delta.substr(1, delta.length() - 1));

	if (shouldAdd) 
		currentProduction[name] += change;
	else
		currentProduction[name] -= change;
}

set<int> determineWinners() { // return the keys in currentProduction with the greatest values
	set<int> winnerKeys; 
	int currentMaxProduction = -10000;
	for (auto u : currentProduction) {
		if (u.second == currentMaxProduction) {
			winnerKeys.insert(u.first);
		}
		if (u.second > currentMaxProduction) { 
			currentMaxProduction = u.second;
			winnerKeys.clear();
			winnerKeys.insert(u.first);
		}
	}
	return winnerKeys;
}

void updateWinners() { 
	winnerSet = determineWinners();
}




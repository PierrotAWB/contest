#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <tuple>
#include <vector>

using namespace std; 

struct entry {
	int day;
	int id; 
	string delta;
};

bool comp(entry a, entry b);
void process(entry a);
bool shouldChangeDisplay(entry a);

int N, G, maxProd, n_changes = 0;

vector<entry> logBook;
map<int, int, greater<int> > cow; /// maps ID to production level
set<int> winner; // set of cow winners

int main() {
	// handle input
	ifstream fin("measurement.in");
	fin >> N >> G;
	for (int i = 0; i < N; i++)
	{
		int day, id; 
		string delta; 
		entry Entry; 

		fin >> day >> id >> delta; 
		
		Entry.day = day; Entry.id = id; Entry.delta = delta;
		cow[id] = G;
		winner.insert(id);
		logBook.push_back(Entry);
	}
	fin.close();
	cow[-2] = G; // to represent the other cows
	winner.insert(-2);

	maxProd = G; // this is the current best level of production across all cows
	sort(logBook.begin(), logBook.end(), comp);

	for (int i = 0; i < N; i++) {
		process(logBook[i]);

		for (auto u : cow) {
			cout << u.second << " ";
		}

		cout << logBook[i].day << " " << logBook[i].id << " " << logBook[i].delta << endl;

		// cout << shouldChangeDisplay(logBook[i]) << " " << n_changes << endl;
		if (shouldChangeDisplay(logBook[i])) n_changes++;
	}

	ofstream fout("measurement.out"); 
	fout << n_changes << "\n";
	fout.close();
	return 0;
}

bool comp(entry a, entry b) {
	return a.day < b.day;
}

// update the cow map according to the changes documented in the logbook
void process(entry a) { 
	bool shouldAdd; 
	int change; 

	if (a.delta.at(0) == '+') shouldAdd = true;
	else shouldAdd = false;

	change = stoi(a.delta.substr(1, a.delta.length() - 1));

	if (shouldAdd) {
		cow[a.id] += change;
	} else {
		cow[a.id] -= change;
	}
}

// the motivation behind this method is the fact that
// every time a log is processed, Farmer John's painting display
// will either change, or it won't.
bool shouldChangeDisplay(entry a) {
	if (cow[a.id] == maxProd){ // it must have come from below
		// cout << "EQUAL " << endl;
		winner.insert(a.id);
		return true;
	}

	if (cow[a.id] > maxProd){ // lone wolf
		// cout << "GREATER " << endl;
		maxProd = cow[a.id];
		if (winner.size() == 1 && winner.count(a.id) > 0) { // the lone wolf was already winning; he continues to beast
			return false;
		} else { // a lone wolf pulls ahead
			winner.clear();
			winner.insert(a.id);
			return true;
		}
	}

	if (cow[a.id] < maxProd) {
		// cout << "LESS THAN " << endl;
		if (winner.count(a.id) == 0) { // wasn't in winning group anyway
			return false;
		}

		 else {
			// the cow changed was formerly a winner;
			// could be a lone wolf (above everyone else) or with the group
			if (winner.size() == 1) {
				// perhaps the lone wolf dropped below others:
				int newMax = -1000;

				// find the maximum after the winner decreases
				for (auto u : cow)
					if (u.second > newMax)
						newMax = u.second;

				int winnerCount = 0;
				set<int> newWinner;

				for (auto u : cow)
					if (u.second == newMax){
						winnerCount++;
						newWinner.insert(u.first);
					}

				maxProd = newMax;
				
				if (newWinner == winner) { // lone wolf continues to win
					return false;
				} else {
					winner = newWinner;
					return true;
				}

			} else {
				return true; // dropped out of the winner's circle
			}
		}

	}

	return false;
}
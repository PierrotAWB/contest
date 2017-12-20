#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// whether node has been visited in DFS check
bool visited[1000000];
// working set in this DFS
int working[1000000];
// graph
vector<int> adj[1000000];
// number of cows
int numCows;

int depth = 1;

int stat = 0;

void dfs(int n) {
    cout << "root:" << n << endl;
    // cout << n << endl;
    // cout << "-" << working[n] << endl;
    // if in working set
    if (working[n] > 0) {
        stat += depth - working[n];
        return;
    }

    if (visited[n]) {
        return;
    }

    // mark as visited and part of working set
    visited[n] = true;
    working[n] = depth;
    depth++;

    for (auto a : adj[n]) { // for every neighboring node to this node
        dfs(a);
    }
}

int main() {
    string PROBLEM_ID = "shuffle";
    ifstream fin;
    fin.open(PROBLEM_ID + ".in");
    ofstream fout;
    fout.open(PROBLEM_ID + ".out");

    fin >> numCows; // number of cows

    int itemp;

    for (int i = 0; i < numCows; i++) {
        fin >> itemp;
        adj[i] = {itemp-1};
    } // adjacency list created

    // check for cycles in adjacency list

    for (int i = numCows-1; i >= 0; i--) {
        if (visited[i] == 0) { // if not visited, do a cycle check
            // reset working set
            for (int a = 0; a < numCows; a++) {
                working[a] = 0;
            }
            // reset depth
            depth=1;

            // cout << "root:" << i << endl;
            dfs(i);
        }
    }

    fout << stat << "\n";
    cout << stat << endl;

    fout.close(); return 0;
}
/*
ID: andreww7
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    //ofstream fout ("gift1.out");
    //ifstream fin ("gift1.in");

    int NP;
    cin >> NP;

    string names[NP];
    map<string, int> balances;

    for (int i = 0; i < NP; i++){
        cin >> names[i];
    }

    for (int i = 0; i < NP; i++){
        balances[names[i]] = 0;
    }

    for (int i = 0; i < NP; i++){
        // declarations
        string name;
        int initialBalance, numRecipients, giftAmount;

        // input section
        cin >> name >> initialBalance >> numRecipients;

        // use input in calculation and assignment
        if (numRecipients > 0) {
            giftAmount = (int) initialBalance / numRecipients;
            for (int j = 0; j < numRecipients; j++ ){
                string recipient;
                cin >> recipient;
                balances[recipient] += giftAmount;
            }
            balances[name] -= giftAmount * numRecipients;
        } else {
            continue;
        }
    }

    for (int i = 0; i < NP; i++) {
        cout << names[i] << " " << balances[names[i]] << endl;
    }

    return 0;
}


/*
ID: andreww7
PROG: ride
LANG: C++
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int computeWordScore(string s) {
    int product = 1;
    int i = 0;
    while (i < s.length()){
        if ((int) s.at(i) >= 65 && (int) s.at(i) <= 90) {
            product *= (int) s.at(i) - 64;
        } else {
            break;
        }
        i++;
    }
    return product % 47;
}

int main()
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string groupName, cometName;
    fin >> groupName >> cometName;

    if (computeWordScore(groupName) == computeWordScore(cometName)) {
        fout << "GO" << endl;
    } else{
        fout << "STAY" << endl;
    }
    return 0;
}

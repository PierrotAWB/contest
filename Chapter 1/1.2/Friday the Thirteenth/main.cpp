/*
ID: andreww7
PROG: friday
LANG: C++
*/

using namespace std;

#include <iostream>
#include <fstream>

bool isLeap(int n) {
    if (n % 4 == 0) {
        if (n % 100 == 0) {
            if (n % 400 == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");

    int N;
    fin >> N;

    int dayCounter [7] = { 0, 0, 0, 0, 0, 0, 0 };
    int daysInMonths [12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int accumulator = 13;
    for (int i = 1900; i < 1900 + N; i++) { // iterate through the days of the years 1900 up to 1900 + N - 1
        if (isLeap(i) == false) {
            for (int j = 0; j < 12; j++) {
                dayCounter[accumulator % 7]++;
                accumulator += daysInMonths[j];
            }
        } else {
            for (int j = 0; j < 12; j++) {
                dayCounter[accumulator % 7]++;
                accumulator += daysInMonths[j];
                if (j == 1) {
                    accumulator++;
                }
            }
        }
    }

    fout << dayCounter[6] << " " << dayCounter[0] << " ";
    for (int i = 1; i < 5; i++ ) {
        fout << dayCounter[i] << " ";
    }
    fout << dayCounter[5] << endl;
    return 0;
}

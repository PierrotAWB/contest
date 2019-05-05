/*
ID: andreww7
PROG: paint
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream fout ("paint.out");
    ifstream fin ("paint.in");

    int a, b, c, d;
    fin >> a >> b >> c >> d;
    if (a > d + 1 || c > b + 1) { // two are disjoint
        fout << b - a + d - c << endl;
    } else if (a < c) {
        if (d >= b) {
            fout << d - a << endl;
        } else {
            fout << b - a << endl;
        }
    } else if (a > c) {
        if (b > d) {
            fout << b - c << endl;
        } else {
            fout << d - c << endl;
        }
    } else {
        fout << d - a << endl;
    }

    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string transformStr(string s);

int main()
{
    string word;
    getline(cin, word);
    cout << transformStr(word);
    return 0;
}

string transformStr(string s) {
    int lcount = 0; int ucount = 0;

    for (int i = 0; i < (int) s.length(); i++) {
        if ((int) s.at(i) >= 65 && (int) s.at(i) <= 90) {
            ucount++;
        } else if ((int) s.at(i) >= 97 && (int) s.at(i) <= 122) { // assume all chars are letters
            lcount++;
        } else {
            ;
        }
    }

    cout << ucount << " " << lcount << endl;

    if (ucount == lcount){
        goto exitLabel;
    } else if (ucount < lcount) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    } else {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    }
    exitLabel: return s;
}

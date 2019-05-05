#include <iostream>
#include <string>

using namespace std;

string add(string a, string b);
string subtract(string a, string b); // always returns positive difference

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string m, n;
        cin >> m >> n;

        if (m.at(0) != '-' && n.at(0) != '-') {             // both pos
            cout << add(m, n) << "\n";
        } else if (m.at(0) == '-' && n.at(0) == '-') {      // both neg
            cout << "-" << add(m, n) << "\n";
        } else if (m.at(0) != '-' && n.at(0) == '-') {      // a - b
            if (m.length() >= n.length() - 1 && (int) m.at(0) >= (int) n.at(1) &&
                m.at(1) >= n.at(2)){
                    cout << subtract(m, n) << "\n";
            } else {                                        // result is negative
                    cout << "-" << subtract(n, m) << "\n";  // this handles the negative sign
            }
        } else {                                            // b - a
            if (m.length() - 1 <= n.length() && (int) m.at(1) <= (int) n.at(0) &&
                m.at(2) >= n.at(1)) {                     // compare first 7 digits
                    cout << subtract(n, m) << "\n";
            } else {                                        // result is negative
                    cout << "-" << subtract(m, n) << "\n";  // this handles the negative sign
            }
        }
    }
    return 0;
}

string add(string a, string b) {
    int x = atoi(a.c_str());
    int y = atoi(b.c_str());
    int z = x + y;
    string c = std::to_string(z);
    return c;
}

string subtract(string a, string b) {  // assert that a > b
    string ansStr = "";
    int ans = (int) a - (int) b;
    string ansStr += (string) ans;
    return ansStr;
}

#include <iostream>
#include <set>

using namespace std;

int main()
{
    int C;
    set<bool> s;

    cin >> C;

    for (int i = 0; i < C; i++) {
        int instruction; bool element;
        cin >> instruction;
        if (instruction != 4){
            cin >> element;
        }

        switch(instruction) {
            case 1:
                if (s.count(element) == 0) { // successfully inserted
                    cout << "true";
                    s.insert(true);
                } else {
                    cout << "false";
                }
                break;
            case 2:
                if (s.count(element) != 0) { // successfully removed
                    cout << "true";
                    s.erase(s.find(element));
                } else {
                    cout << "false";
                }
                break;
            case 3:
                if (s.count(element) != 0) {
                    if (element == true) cout << 1;
                    if (element == false) cout << 0;
                else {
                    cout << -1;
                }
                break;
            case 4:
                for (std::set<int>::iterator it = s.begin(); it != s.end(); it++) {
                    cout << *it;
                }
                break;
        }
    }
    return 0;
}

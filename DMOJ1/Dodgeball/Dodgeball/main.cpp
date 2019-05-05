//
//  main.cpp
//  Dodgeball
//
//  Created by Andrew Wang on 2017-07-02.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string kid[5];

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    int choices = 0;
    
    for (int i = 0; i < N; i++){
        cin >> kid[i];
    }
    
    char currentStartLetter = kid[0].at(0);
    int consecKidCounter = 0;
    
    for (int j = 0; j < 5; j++) {
        if (kid[j] == "") {
            choices += consecKidCounter * (consecKidCounter + 1) / 2;
            break;
        }
        if (tolower(kid[j].at(0)) == tolower(currentStartLetter)){
            consecKidCounter ++;
        } else {
            choices += consecKidCounter * (consecKidCounter + 1) / 2;
            consecKidCounter = 1;
            currentStartLetter = kid[j].at(0);
        }
    }
    
    cout << choices << endl;
    
    return 0;
}

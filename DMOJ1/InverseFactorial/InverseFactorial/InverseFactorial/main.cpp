//
//  main.cpp
//  InverseFactorial
//
//  Created by Andrew Wang on 2017-07-02.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <cstdlib>

using namespace std;

string add(string a, string b){
    string answer = "";
    int aLen = a.length(); int bLen = b.length();
    int difference = abs(aLen - bLen);
    
    if (difference == 0){
        continue;
    } else {
        (aLen > bLen) ? bLen = bLen:
    }
    
    int carry = 0;
    
    for (int i = 0; i < max(aLen, bLen); i++){
        int temp;
        temp = (int) a.at(i) - (int) b.at(i) - 96 + carry;
        
        div_t divRes = div(temp, 10);
        temp = divRes.rem;
        carry = divRes.quot;
        
        answer = (char) (temp + 48) + answer;
    }
}

string multiply(string a, string b){
    string = answer;
    for (int i = b.length() - 1; i >= 0; i--){
        int carry = 0;
        for (int j = a.length() - 1; j >= 0; j--){
            int temp;
            answer.push_back((int)b.at(i) * (int)(a.at(j)));
            
        }
    }
}

int main(int argc, const char * argv[]) {
    string fact;
    cin >> fact;
    
    int zeroCounter = 0; int i = fact.length() - 1;
    while (fact.at(i) == '0'){
        zeroCounter ++;
        i --;
    }
    
    cout << zeroCounter;
    return 0;
}

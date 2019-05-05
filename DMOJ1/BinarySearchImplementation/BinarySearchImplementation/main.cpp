//
//  main.cpp
//  BinarySearchImplementation
//
//  Created by Andrew Wang on 2017-07-03.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

// Written on HackerRank.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

int binSearch(int array[], int size, int key){
    int a = 0; int b = size - 1;
    while (a <= b){
        int k = (a + b)/2;
        if (array[k] == key){
            return k;
        }
        (array[k] > key) ? b = k - 1 : a = k + 1;
    }
    return -1;
}

int main() {
    clock_t t = clock();
    double duration;
    
    int V, n;
    cin >> V >> n;
    
    int ar[n];
    
    for (int i = 0; i < n; i++){
        cin >> ar[i];
    }
    cout << binSearch(ar, n, V) << endl;
    duration = (clock() - t) / (double) CLOCKS_PER_SEC;
    cout << duration;
    return 0;
}

#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <vector>

#define watch(x) cout << "CURRENT VALUE: " << x << endl;

using namespace std;

struct offer{
    int quantity;
    int price;
};

int N, M, R;
long long maxProfit = 0;

int production[100001];
offer buy[100002];
int rent[100001];

bool offerComp(offer a, offer b) {
    return a.price < b.price;
}

int main() {
    ifstream fin("rental.in");
    fin >> N >> M >> R;
    for (int i = 0; i < N; i++) {
        fin >> production[i];
    }
    for (int i = 0; i < M; i++) {
        int q, p;
        fin >> q >> p;
        offer Offer;
        Offer.quantity = q;
        Offer.price = p;
        buy[i] = Offer;
    }
    for (int i = 0; i < R; i++) {
        fin >> rent[i];
    }
    fin.close();
    
    sort(production, production + N);
    reverse(production, production + N);
    
    sort(buy, buy + M, offerComp);
    reverse(buy, buy + M);
    
    sort(rent, rent + R);
    reverse(rent, rent + R);
    
    // set the threshold for renting higher and higher until R
    for (int i = 0; i < R; i++) {
        bool skip =  false;
        long long profit = 0;
        
        if (i == 3)
            cout << "OK" << endl;
        
        // add profit from rent
        for (int j = 0; j < i; j++)
            profit += rent[j];
        
        // add profit from milk
        offer offers[100002];
        copy(buy, buy + M, offers);
        
        int index = 0;
        
        for (int j = 0; j < N - i; j++) { // check these indices
            if (offers[index].quantity == 0 || production[j] == 0) {
                skip = true;
                break;
            }
            if (production[j] < offers[index].quantity) {
                profit += production[j] * offers[index].price;
                offers[index].quantity -= production[j];
            } else {
                int a = production[j];
                while (a > 0){
                    profit += min(offers[index].quantity, a) * offers[index].price; // as much as you can;
                    int change = min(offers[index].quantity, a);
                    offers[index].quantity -= change;
                    a -= change;
                    
                    if (offers[index].quantity == 0)
                        index++;
                }
            }
        }
        if (skip) continue;
        
        if (profit > maxProfit)
            maxProfit = profit;
    }
    
    ofstream fout("rental.out");
    fout << maxProfit << "\n";
    fout.close();
    return 0;
}
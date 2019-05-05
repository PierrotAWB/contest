#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

#define L_SIZE 200
#define CANDIDATE_RANGE 1477

using namespace std;
typedef long long ll;
bool isPrime(ll k);

vector<ll> candidate;
int l[L_SIZE];

ll modul(ll a, ll b) {
    if (remainder(a, b) > 0) return remainder(a, b);
    else return remainder(a, b) + b;
}

int main(){
    ll N;
    cin >> N;

    int index = 1, i = 0;
    while (i < L_SIZE){
        if (isPrime(index)) {
            l[i] = index;
            i++;
        }
        index++;
    }
    for (ll i = N; i < N + CANDIDATE_RANGE; i++) {
        candidate.push_back(i);
    }     

    // partial sieve
    for (int i = 0; i < L_SIZE; i++) {
        ll k = modul(N, l[i]);
        for (ll j = N + l[i] - k; j < N + CANDIDATE_RANGE; j+= l[i]) {
            if (find(candidate.begin(), candidate.end(), j) != candidate.end()) {
                candidate.erase(remove(candidate.begin(), candidate.end(), j), candidate.end());
            }
        }
    }

    // for (auto u : candidate) cout << u << " ";

    for (auto u : candidate) {
        if (isPrime(u)) {
            cout << u << "\n";
            break;
        }
    }
    return 0;
}

bool isPrime(ll k) {
    if (k < 2) {
        return false;
    } else if (k == 2 || k == 3){
        return true;
    }
    if (remainder(k, 2) == 0) return false;
    for (int i = 3; i < (ll) pow(k, 0.5) + 1; i+=2) {
        if (remainder(k, i) == 0){ // not prime; immediately reject
            return false;
        }
    }
    return true;
}
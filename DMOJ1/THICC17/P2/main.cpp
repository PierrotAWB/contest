#include <iostream> 
#include <math.h>
#define MOD (int)(1e9 + 7) // define does not include a semi colon (preprocessing) 
typedef unsigned int ll; 
using namespace std; 
ll modulo (ll a, ll b) { 
	lldiv_t divRes = lldiv(a, b); 
	return divRes.rem;
}
int main() { 
	int N, A0, B; 
	ll accum, squareAccum, M, prev;
	cin >> N >> A0 >> B >> M; 
	accum = prev = A0; squareAccum = (A0 % M * A0 % M) % M;
	for (int i = 1; i < N; i++) { 
		ll Ai = (prev * B) % M;
		prev = Ai;
		accum = (accum + Ai % MOD) % MOD; 
		squareAccum = modulo(squareAccum + (Ai % MOD * Ai % MOD), MOD); 
	}
	cout << modulo(accum % MOD * accum % MOD - squareAccum % MOD, MOD) << endl;
	return 0;
}
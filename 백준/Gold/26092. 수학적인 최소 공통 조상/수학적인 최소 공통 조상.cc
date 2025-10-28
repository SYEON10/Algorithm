#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MAX = 1e12;
vector<ll> primes;

vector<ll> GetPrimes(ll a){
    vector<ll> a_primes;
    for(ll i = 0; i < primes.size(); i++){
        while(a % primes[i] == 0){
            a /= primes[i];
            a_primes.push_back(primes[i]);
        }
    }
    if(a != 0) a_primes.push_back(a);
    return a_primes;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    ll a, b;
    cin >> a >> b;

    ll limit = (ll)sqrt(MAX);

    vector<bool> isPrime(limit + 5, true);

    for(ll i = 2; i <= limit; i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(ll j = i * i; j <= limit; j += i){
                isPrime[j] = false;
            }
        }
    }

    vector<ll> a_primes = GetPrimes(a);
    vector<ll> b_primes = GetPrimes(b);

    ll a_i = 0;
    ll b_i = 0;
    while(true){
        if(a == b) break;
        if(a == 1 || b == 1) {
            a = 1;
            break;
        }
        if(a > b){
            a /= a_primes[a_i];
            a_i++;
        }
        else{
            b /= b_primes[b_i];
            b_i++;
        }
    }

    cout << a;

    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//소인수분해
//1. 소수를 찾는다.
//2. 소수로 나눈다.

const int MAX = 5'000'001;
vector<int> primes;

void prime_factorization(int num){
    for(int i = 0; i < primes.size();i++){
        while(num % primes[i] == 0){
            num /= primes[i];
            cout << primes[i] << ' ';
        }
    }
    if(num != 1) cout << num;
    cout << '\n';
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    vector<bool> isPrime(MAX, true);

    for(int i = 2; i * i < MAX; i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j = i * i; j < MAX; j += i){
                isPrime[j] = false;
            }
        }
    }

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        prime_factorization(num);
    }

    return 0;
}
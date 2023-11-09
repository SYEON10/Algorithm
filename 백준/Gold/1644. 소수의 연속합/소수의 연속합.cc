#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    if(n == 1){
        cout << 0;
        return 0;
    }
    
    vector<bool> primeCheck(n + 1, true);
    vector<int> primes;

    primeCheck[0] = false;
    primeCheck[1] = false;

    for(int i = 2; i <= sqrt(n); i++){
        if(primeCheck[i]){
            for(int j = 2; j * i <= n; j++){
                primeCheck[j * i] = false;
            }
        }
    }

    for(int i = 2; i <= n; i++){
        if(primeCheck[i]){
            primes.push_back(i);
        }
    }

    int left = 0, right = 0, window = primes[0], count = 0;

    while(right < primes.size()){
        if(window == n){
            window += primes[++right] - primes[left++];
            count++;
        }
        if(window < n){
            window += primes[++right];
        }
        if(window > n){
            window -= primes[left++];
        }
    }

    cout << count;

    return 0;
}
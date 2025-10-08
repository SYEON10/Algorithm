#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX = 123456 * 2;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    vector<int> primes;
    vector<bool> nums(MAX + 1, false);

    for(int i = 2; i * i <= MAX; i++){
        if(!nums[i]){
            for(int j = i * i; j <= MAX; j += i){
                nums[j] = true;
            }
        }
    }

    for(int i = 2; i <= MAX; i++){
        if(!nums[i]){
            primes.push_back(i);
        }
    }

    int input;
    while(cin >> input && input != 0){
        int count = upper_bound(primes.begin(), primes.end(), input * 2) - upper_bound(primes.begin(), primes.end(), input);
        cout << count << '\n';
    }

    return 0;
}
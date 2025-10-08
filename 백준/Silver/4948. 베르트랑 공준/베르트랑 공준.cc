#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX = 500000;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    vector<int> primes;
    bool nums[MAX + 1];

    for(int i = 2; i <= MAX; i++){
        if(!nums[i]){
            primes.push_back(i);
            for(int j = 2; j <= ceil(MAX / i); j++){
                nums[j * i] = true;
            }
        }
    }

    int input;
    while(true){
        cin >> input;
        if(input == 0) break;

        vector<int>::iterator last = lower_bound(primes.begin(), primes.end(), input * 2);
        
        int count = last - upper_bound(primes.begin(), primes.end(), input);

        if(*last == input * 2) count++;
        cout << count << '\n';
    }

    return 0;
}
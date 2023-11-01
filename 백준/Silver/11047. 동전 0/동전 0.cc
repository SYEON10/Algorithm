#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    
    int n, k, x, count = 0;
    cin >> n >> k;
    
    vector<int> coins;
    
    while(n--){
        cin >> x;
        coins.push_back(x);
    }
   
    sort(coins.begin(), coins.end(), greater<>());
    
    for(const auto& coin : coins){
        while(k - coin >= 0){
            k -= coin;
            count++;
        }
        if(coin == 0){
            break;
        }
    }
    
    cout << count;

    return 0;
}
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAX = 1e6 + 1;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    set<int> coins;
    vector<int> DP(k + 1, MAX);

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x <= k){
            coins.insert(x);
            DP[x] = 1;
        }
    }

    DP[0] = 0;

    for(int i = 1; i <= k; i++){
        for(int coin : coins){
            if(i - coin > 0){
                DP[i] = min(DP[i], DP[i - coin] + 1);
            }
        }
    }

    if(DP[k] == MAX) cout << -1;
    else cout << DP[k];

    return 0;
}
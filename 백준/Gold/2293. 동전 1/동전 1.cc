#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<int> DP(k + 1, 0);
    DP[0] = 1;
    
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        
        for(int j = x; j <= k; j++){
            DP[j] += DP[j - x];
        }
    }

    cout << DP[k];

    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, k, c;
    cin >> n >> k >> c;

    int weight[n + 1] = {};
    int DP[n + 1] = {};
    int prev[n + 1] = {};

    for(int i = 1; i <= n; i++){
        cin >> weight[i];
        if(i < k || DP[i - 1] + weight[i] <= DP[i - k] + c) {
            DP[i] = DP[i - 1] + weight[i];
            prev[i] = i - 1;
            continue;
        }
        DP[i] = DP[i - k] + c;
        prev[i] = i - k;
    }

    cout << DP[n] << '\n';

    int curr = n;
    vector<int> route;
    while(curr > 0){
        if(prev[curr] == curr - 1 && DP[curr] - weight[curr] == DP[curr - 1]) {
            curr--;
            continue;
        }
        route.push_back(prev[curr] + 1);
        curr -= k;
    }

    cout << route.size() << '\n';

    if(!route.empty()){
        for(int r : route){
            cout << r << ' ';
        }
    }

    return 0;
}
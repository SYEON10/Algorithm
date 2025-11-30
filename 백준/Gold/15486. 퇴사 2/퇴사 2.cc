#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    vector<pair<int, int>> schedules(n + 1);
    vector<int> DP(n + 2, 0);
    for(int i = 1; i <= n; i++){
        int t, p;
        cin >> t >> p;
        schedules[i] = {t, p};
    }

    for(int i = n; i >= 1; i--){
        if(i + schedules[i].first - 1 > n){
            DP[i] = DP[i + 1];
            continue;
        }
        DP[i] = max(DP[i + 1], DP[i + schedules[i].first] + schedules[i].second);
    }

    cout << DP[1];

    return 0;
}
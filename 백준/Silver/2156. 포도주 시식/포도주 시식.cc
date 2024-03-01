#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> glasses(n + 1);
    vector<int> DP(n + 1);

    for(int i = 1; i <= n; i++)
        cin >> glasses[i];

    DP[0] = 0;
    DP[1] = glasses[1];
    DP[2] = glasses[1] + glasses[2];

    for(int i = 3; i <= n; i++){
        DP[i] = max(DP[i-3] + glasses[i-1] + glasses[i], DP[i-2] + glasses[i]);
        DP[i] = max(DP[i], DP[i-1]);
    }

    cout << DP[n];

    return 0;
}
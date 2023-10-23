#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> stairs(n + 1, 0);

    for(int i = 1; i < n + 1; i++){
        cin >> stairs[i];
    }

    vector<int> DP(n + 1, 0);
    DP[1] = stairs[1];
    DP[2] = stairs[1] + stairs[2];

    for(int i = 3; i <= n; i++){
        DP[i] = max(DP[i - 2], DP[i - 3] + stairs[i - 1]) + stairs[i];
    }

    cout << DP[n];

    return 0;
}

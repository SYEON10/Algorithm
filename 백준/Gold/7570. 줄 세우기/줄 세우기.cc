#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// 앞이나 뒤로 보내지 않아도 되는 수
// = 가장 긴 증가하는 수열(이때, 증가는 +1을 의미한다)

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    int nums[n + 1];
    int DP[n + 1] = {};

    int max_value = 0;

    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        DP[x] = DP[x - 1] + 1;

        max_value = max(max_value, DP[x]);
    }

    cout << n - max_value;

    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, s;
    cin >> n >> s;

    vector<int> nums(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int left = 0, right = 0;
    int before_left = -1, before_right = -1;
    int ans = INT32_MAX;
    sum = nums[left];

    while (!(before_left == left && before_right == right)) {
        before_left = left;
        before_right = right;
        if (sum >= s) {
            ans = min(ans, right - left + 1);
            sum -= nums[left++];
            continue;
        }
        if (right < n - 1) {
            sum += nums[++right];
        }
    }

    if (ans == INT32_MAX) cout << 0; //코너케이스 - 주어진 숫자들로 만들 수 없을 때
    else cout << ans;

    return 0;
}
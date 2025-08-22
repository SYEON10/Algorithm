#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// 4 2 6 3 1 5 -> 이거야말로 LIS 문제임
//오랜만에 LIS 구현해볼 것

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    int nums[n];
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector<int> LIS(n, 0);

    int end = 0;

    for(int i = 0; i < n; i++){
        if(nums[i] > LIS[end]){
            LIS[end + 1] = nums[i];
            end++;
            continue;
        }

        *lower_bound(LIS.begin(), LIS.begin() + end, nums[i]) = nums[i];
    }

    cout << end;

    return 0;
}
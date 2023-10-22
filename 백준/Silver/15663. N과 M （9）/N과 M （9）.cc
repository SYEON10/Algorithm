#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> printer;
vector<bool> checker;
vector<int> nums;

void BackTracking(int idx){
    if(idx == m){
        for(int i = 0; i < m; i++){
            cout << printer[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int prev = 0;
    for(int i = 0; i < n;i++){
        if(!checker[i] && prev != nums[i]){
            prev = nums[i];
            printer[idx] = nums[i];
            checker[i] = true;
            BackTracking(idx + 1);
            checker[i] = false;
        }
    }
}

int main() {

    cin >> n >> m;

    nums.assign(n, 0);
    checker.assign(n, false);
    printer.assign(m, 0);

    for(auto& num : nums){
        cin >> num;
    }

    sort(nums.begin(), nums.end());

    BackTracking(0);

    return 0;
}
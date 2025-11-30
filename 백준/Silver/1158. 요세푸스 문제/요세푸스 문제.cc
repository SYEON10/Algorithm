#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for(int i = 1; i <= n; i++){
        nums[i - 1] = i;
    }

    int curr = 0;
    cout << '<';
    for(int i = 0; i < n; i++){
        curr += (k - 1);
        curr %= nums.size();
        cout << nums[curr];
        if(nums.size() != 1){
            cout << ", ";
        }
        nums.erase(nums.begin() + curr);
    }

    cout << '>';

    return 0;
}
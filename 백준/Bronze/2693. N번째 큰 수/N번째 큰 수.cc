#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--){
        vector<int> nums(10);
        for(int i = 0; i < 10; i++){
            cin >>nums[i];
        }

        sort(nums.begin(), nums.end(), greater<>());

        cout << nums[2] << '\n';
    }

    return 0;
}
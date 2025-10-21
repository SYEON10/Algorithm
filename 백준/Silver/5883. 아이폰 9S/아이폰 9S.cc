#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//N < 1000
//O(N^2) 가능

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    int nums[n] = {};

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int result = 0;
    for(int curr = 0; curr < n; curr++){
        int length = 0;
        int curr_length = 1;
        int prev = -1;
        for(int next = 0; next < n; next++){
            if(nums[next] == nums[curr]) continue;
            if(nums[next] == prev) {
                curr_length++;
                length = max(length, curr_length);
            }
            else{
                curr_length = 1;
                length = max(length, curr_length);
                prev = nums[next];
            }
        }
        result = max(length, result);
    }

    cout << result;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //입력
    int n;
    cin >> n;

    vector<int> nums(n);

    for(auto& num : nums)
        cin >> num;

    sort(nums.begin(), nums.end());

    //투포인터
    int left = 0, right = n - 1, value;
    int closestVal = INT_MAX, closestLeft, closestRight;

    while(left < right){
        value = nums[left] + nums[right];

        if(value == 0){
            cout << nums[left] << " " << nums[right];
            return 0;
        }

        if(abs(closestVal) > abs(value)){
            closestLeft = left;
            closestRight = right;
            closestVal = value;
        }

        if(value > 0){
            right--;
        }
        if(value < 0){
            left++;
        }
    }

    cout << nums[closestLeft] << " " << nums[closestRight];

    return 0;
}
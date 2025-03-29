#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

//세 용액을 섞을 시 int 범위를 넘어설 수 있음
//한 용액을 고정해볼까?

int main()
{
    int n;
    cin >> n;

    vector<long long> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    long long min_value = LONG_LONG_MAX;
    int ans_left, ans_mid, ans_right;

    for(int left = 0; left < n - 2; left++){
        int mid = left + 1;
        int right = n - 1;

        while(mid < right){
            long long value = nums[left] + nums[mid] + nums[right];

            if(value == 0) {
                cout << nums[left] << ' ' << nums[mid] << ' ' << nums[right];
                return 0;
            }

            if(abs(value) < abs(min_value)){
                ans_left = left;
                ans_mid = mid;
                ans_right = right;
                min_value = value;
            }

            if(value < 0){
                mid++;
            }

            if(value > 0){
                right--;
            }
        }
    }


    cout << nums[ans_left] << ' ' << nums[ans_mid] << ' ' << nums[ans_right];

    return 0;
}
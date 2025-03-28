#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    if(n < 2){
        cout << 0;
    }

    sort(nums.begin(), nums.end());

    int count = 0;

    for(int i = 0; i < n; i++){
        int left = 0;
        int right = n-1;
        while(left < right){
            
            if(left == i){
                left++;
                continue;
            }
            if(right == i) {
                right--;
                continue;
            }
                            
            int value = nums[left] + nums[right];

            if(value == nums[i]){
                count++;
                break;
            }

            if(value < nums[i]){
                left++;
            }
            if(value > nums[i]){
                right--;
            }
        }
    }

    cout << count;

    return 0;
}
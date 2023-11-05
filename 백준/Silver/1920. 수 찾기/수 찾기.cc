//
// Created by syeon on 2023-11-01.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//vec 의 정렬을 가정
bool IsExist(const vector<int> &nums, const int check){

    int left = 0;
    int right = int(nums.size()) - 1;
    int mid;

    while(left <= right){
        mid = (left + right) / 2;

        if(nums[mid] == check)
            return true;
        if(nums[mid] < check){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    return false;
}

int main()
{
    //입력
    int numsSize, checkNumSize;
    cin >> numsSize;

    vector<int> nums(numsSize);

    for(int idx = 0; idx < numsSize; idx++){
        cin >> nums[idx];
    }

    cin >> checkNumSize;

    vector<int> checkNum(checkNumSize);

    for(int idx = 0; idx < checkNumSize; idx++){
        cin >> checkNum[idx];
    }

    //연산 및 출력
    sort(nums.begin(), nums.end());

    for(const auto& check : checkNum){
        cout << IsExist(nums, check) << '\n';
    }

    return 0;
}
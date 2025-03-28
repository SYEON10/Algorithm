#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int main(){    
    int n, m;
    cin >> n >> m;
    
    vector<int> nums(n);
    
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    sort(nums.begin(), nums.end());
   
    int left = 0;
    int right = 0;
    int closest = 2e9;
    
    while(right < n && left <= right){
        int value = nums[right] - nums[left];

        if(value < m) {right++;continue;}
        if(value < closest) {closest = value;continue;}

        left++;
    }
       
    cout << closest;
    
    return 0;

}
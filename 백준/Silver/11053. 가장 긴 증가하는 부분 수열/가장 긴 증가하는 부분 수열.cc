#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, count = 1;
    cin >> n;

    vector<int> nums(n, 0);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector<int> DP(n, 1);

    for(int i = 1; i < n; i++){ //숫자 순회
        for(int j = 0; j < i; j++){ //뒤로 가며 자신보다 작은 숫자 찾기
            if(nums[i] > nums[j]){
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
        count = max(count, DP[i]);
    }

    cout << count;

    return 0;
}
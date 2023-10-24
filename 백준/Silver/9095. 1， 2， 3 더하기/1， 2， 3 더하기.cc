#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> nums(n, 0);
    
    for(auto& num : nums){
        cin >> num;
    }
    
    vector<int> DP(12, 0); //n은 11보다 작음
    
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    
    for(int i = 4; i <= 11; i++){
        DP[i] = (DP[i - 1] * DP[1]) + (DP[i - 2] * (DP[2] - 1)) + (DP[i - 3] * (DP[3] - 3));
    }
    
    for(const auto& num : nums){
        cout << DP[num] << '\n';
    }

    return 0;
}
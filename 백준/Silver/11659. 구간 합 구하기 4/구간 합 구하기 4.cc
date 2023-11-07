#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, i, j;
    cin >> n >> m;

    vector<int> nums(n);
    for(auto & num : nums){
        cin >> num;
    }

    vector<int> prefix(n + 1, 0);
    //누적합 계산

    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i - 1] + nums[i - 1];
    }

    while(m--){
        cin >> i >> j;
        cout << (prefix[j] - prefix[i - 1]) << '\n';
    }

    return 0;
}
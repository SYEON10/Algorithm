#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    //1 = cy, 2 = sk, 0 = 빔
    vector<int> DP(n + 1, 0);

    DP[1] = 1;
    DP[2] = 0;
    DP[3] = 1;
    DP[4] = 1;

    vector<int> getCount = {1, 3, 4};

    for(int i = 5; i < n + 1; i++){
        for(int j = 0; j < getCount.size(); j++){
            DP[i] += DP[i - getCount[j]];
        }
        if(DP[i] == 3){
            DP[i] = 0;
        }
        else DP[i] = 1;
    }

    cout << ((DP[n] == 1) ? "SK" : "CY");

    return 0;
}
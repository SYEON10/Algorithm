#include <iostream>
#include <vector>

using namespace std;


int main() {

    int n;
    cin >> n;

    vector<vector<int>> DP(n + 1, vector<int>(10, 0));

    for(int i = 1; i <= 9; i++){
        DP[1][i] = 1;
    }

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= 8; j++){
            DP[i][j] = (DP[i-1][j-1] + DP[i-1][j+1])%1000000000;
        }
        DP[i][0] = DP[i-1][1];
        DP[i][9] = DP[i-1][8];
    }

    int result = 0;
    for(int i = 0; i <= 9; i++){
        result = (result + DP[n][i]) % 1000000000;
    }

    cout << result;

    return 0;
}
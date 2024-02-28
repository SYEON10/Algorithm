#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<vector<int>> triangle(n + 2, vector<int>(n + 2, 0));
    vector<vector<int>> DP(n + 2, vector<int>(n + 2, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> triangle[i][j];
        }
    }

    DP[1][1] = triangle[1][1];

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            DP[i][j] = max(DP[i-1][j-1], DP[i-1][j]) + triangle[i][j];
        }
    }

    cout << *max_element(DP[n].begin(), DP[n].end());

    return 0;
}
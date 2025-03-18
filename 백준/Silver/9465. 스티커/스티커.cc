#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Sticker(){
    int n;
    cin >> n;

    vector<vector<int>> table(2, vector<int>(n + 1, 0));

    //1행/2행 i열의 최대 점수
    for(int r = 0; r < 2; r++){
        for(int c = 1; c <= n; c++){
            cin >> table[r][c];
        }
    }

    vector<vector<int>> DP(2, vector<int>(n + 1, 0));

    DP[0][1] = table[0][1];
    DP[1][1] = table[1][1];

    //DP[1][i] = max(DP[2][i-1], max(DP[1][i-2], DP[0][i-2])) + table[1][i]
    for(int i = 2; i <= n; i++){
        DP[0][i] = max(DP[1][i-1], max(DP[1][i-2], DP[0][i-2])) + table[0][i];
        DP[1][i] = max(DP[0][i-1], max(DP[1][i-2], DP[0][i-2])) + table[1][i];
    }

    return max(DP[0][n], DP[1][n]);
}

int main()
{
    int t;
    cin >> t;

    vector<int> result(t);

    for(int i = 0; i < t; i++)
        result[i] = Sticker();

    for(int i = 0; i < t; i++)
        cout << result[i] << '\n';
    
    return 0;
}
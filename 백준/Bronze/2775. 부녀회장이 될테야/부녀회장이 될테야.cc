#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0); 

    int t;
    cin >> t;

    while(t--){
        int k, n;
        cin >> k >> n;

        vector<vector<int>> board(k + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= n; i++){
            board[0][i] = i;
        }

        for(int row = 1; row <= k; row++){
            for(int col = 1; col <= n; col++){
                for(int lower = 1; lower <= col; lower++){
                    board[row][col] += board[row - 1][lower];
                }
            }
        }

        cout << board[k][n] << '\n';
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> table;
vector<bool> vertical;
vector<bool> left_diagonal;
vector<bool> right_diagonal;

int n, cnt;

void BackTracking(int row){
    if(row == n + 1){
        cnt++;
        return;
    }

    for(int col = 1; col <= n; col++){
        if(vertical[col] || left_diagonal[row + col - 1] || right_diagonal[n - col + row - 1]){
            continue;
        }

        vertical[col] = true;
        left_diagonal[row + col - 1] = true;
        right_diagonal[n - col + row - 1] = true;

        BackTracking(row + 1);
        
        vertical[col] = false;
        left_diagonal[row + col - 1] = false;
        right_diagonal[n - col + row - 1] = false;
    }
}

int main()
{
    cin >> n;
    cnt = 0;

    vertical.assign(n + 1, false);
    left_diagonal.assign(2 * n, false);
    right_diagonal.assign(2 * n, false);

    BackTracking(1);

    cout << cnt;

    return 0;
}
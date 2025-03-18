#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<vector<bool>>> fenced(m + 1, vector<vector<bool>>(n + 1, vector<bool>(2, false)));

    //DP[r][c] = r, c까지 가는 경우의 수
    vector<vector<long long>> DP(m + 1, vector<long long>(n + 1, 0));

    for(int i = 0; i < k; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int first = x1 + y1;
        int second = x2 + y2;
        if(first > second){
            if(x1 == x2) fenced[y1][x1][1] = true; //수직
            else fenced[y1][x1][0] = true; //수평
        }
        else {
            if(x1 == x2) fenced[y2][x2][1] = true;
            else fenced[y2][x2][0] = true;
        }
    }

    //if 도로가 열려있다면 DP[r][c] = DP[r - 1][c] + DP[r][c - 1];

    DP[0][0] = 1;

    for(int r = 0; r <= m; r++){
        for(int c = 0; c <= n; c++){
            if(r - 1 >= 0 && !fenced[r][c][1]) DP[r][c] += DP[r - 1][c];
            if(c - 1 >= 0 && !fenced[r][c][0]) DP[r][c] += DP[r][c - 1];
        }
    }

    cout << DP[m][n];

    return 0;
}
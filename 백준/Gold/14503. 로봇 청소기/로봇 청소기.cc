#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool CheckAround(const vector<vector<int>>& matrix, int r, int c){
    return matrix[r][c + 1] > 0 && matrix[r + 1][c] > 0 && matrix[r][c - 1] > 0 && matrix[r - 1][c] > 0;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int r, c, d;
    cin >> r >> c >> d;

    unordered_map<int, pair<int, int>> direction{
        {0, {-1, 0}},
        {1, {0, 1}},
        {2, {1, 0}},
        {3, {0, -1}},
    };

    vector<vector<int>> matrix(n, vector<int> (m, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    int count = 0;

    while(true){
        if(matrix[r][c] == 0){
            matrix[r][c] = 2;
            count++;
            continue;
        }
        if(CheckAround(matrix, r, c)){
            //바라보는 방향에 따라 후진
            int rear_r = r - direction[d].first;
            int rear_c = c - direction[d].second;
            //만약 후진이 안 된다면 break;
            if(matrix[rear_r][rear_c] == 1){
                break;
            }
            r = rear_r;
            c = rear_c;
            continue;
        }

        //90도 회전
        if(--d == -1) d = 3;
        //앞 칸이 청소 안 되어 있으면 그 칸으로 전진
        int front_r = r + direction[d].first;
        int front_c = c + direction[d].second;

        if(matrix[front_r][front_c] == 0){
            r = front_r;
            c = front_c;
        }
    }

    cout << count;

    return 0;
}
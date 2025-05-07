#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct point {
    int r;
    int c;
    int time;
};

//1. 불판 기록
//2. 캐릭터 움직이기

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n + 2, vector<int>(m + 2, -1));

    point hoon;
    vector<point> fire;

    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= m; c++) {
            char input;
            cin >> input;
            if (input == '.') matrix[r][c] = 0;
            else matrix[r][c] = -2;
            if (input == 'J') {
                hoon = { r, c, 0 };
                matrix[r][c] = 0;
            }
            if (input == 'F') fire.push_back({ r, c, 0 });
        }
    }

    queue<point> BFS;

    for(int i = 0; i < fire.size(); i++){
        BFS.push(fire[i]);
    }

    vector<pair<int, int>> direction = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

    while (!BFS.empty()) {
        point node = BFS.front();
        BFS.pop();

        for (pair<int, int> dir : direction) {
            int new_r = node.r + dir.second;
            int new_c = node.c + dir.first;

            if(matrix[new_r][new_c] != 0) continue;

            matrix[new_r][new_c] = node.time + 1;
            BFS.push({ new_r, new_c, node.time + 1 });
        }
    }

    BFS.push(hoon);
    matrix[hoon.r][hoon.c] = -2;

    while (!BFS.empty()) {
        point node = BFS.front();
        BFS.pop();

        for (pair<int, int> dir : direction) {
            int new_r = node.r + dir.second;
            int new_c = node.c + dir.first;

            if(matrix[new_r][new_c] == -1){
                cout << node.time + 1;
                return 0;
            }

            //TODO
            if(matrix[new_r][new_c] > node.time + 1 || matrix[new_r][new_c] == 0){
                BFS.push({ new_r, new_c, node.time + 1 });
                matrix[new_r][new_c] = -2;
            }
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}
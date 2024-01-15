#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>

using namespace std;

int PopMovement(vector<vector<int>> &matrix, const int N, const int L, const int R){
    int count = 0;
    queue <pair<int, int>> BFS;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while(true){
        bool open = false;
        //국경선을 연다
        vector<vector<vector<bool>>> adjList(N, vector<vector<bool>>(N, vector<bool>(4, false)));
        vector<vector<bool>> visited(N, vector<bool>(N, false));

        for(int r = 0; r < N; r++){
            for(int c = 0; c < N; c++){
                for(int i = 0; i < 4; i++){
                    int newR = r + dr[i];
                    int newC = c + dc[i];

                    if(newR >= 0 && newR < N && newC >= 0 && newC < N){
                        int diffPop = abs(matrix[newR][newC] - matrix[r][c]);
                        if(diffPop >= L && diffPop <= R){
                            adjList[r][c][i] = true;
                            open = true;
                        }
                    }
                }
            }
        }

        //열린 국경선이 없으면 break;
        if(!open)
            break;

        count++;

        //열린 국경선을 따라 로직 실행

        for(int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {

                if(visited[r][c])
                    continue;

                BFS.push({r, c});
                vector<pair<int, int>> temp;
                int add = 0;

                while(!BFS.empty()){
                    auto[x, y] = BFS.front();
                    BFS.pop();

                    if(visited[x][y])
                        continue;

                    visited[x][y] = true;
                    add += matrix[x][y];
                    temp.push_back({x, y});

                    for(int i = 0; i < 4; i++){
                        if(adjList[x][y][i]){
                            int newX = x + dr[i];
                            int newY = y + dc[i];

                            if(visited[newX][newY])
                                continue;

                            BFS.push({newX, newY});
                        }
                    }
                }

                if(temp.size() == 1)
                    continue;

                for(int i = 0; i < temp.size();i++){
                    matrix[temp[i].first][temp[i].second] = add / temp.size();
                }
            }
        }
    }

    return count;
}

int main()
{
    int n, l, r;
    cin >> n >> l >> r;

    vector<vector<int>> matrix(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    cout << PopMovement(matrix, n, l, r);

    return 0;
}
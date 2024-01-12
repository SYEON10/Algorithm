#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int countArea(const vector<vector<char>>& matrix){

    int n = (int)matrix.size();
    int count = 0;

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> BFS;

    int dr[] = {0, 0,-1, 1};
    int dc[] = {-1, 1, 0, 0};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            if(visited[i][j])
                continue;

            char color = matrix[i][j];

            BFS.push({i, j});

            while(!BFS.empty()){
                auto [row, col] = BFS.front();
                BFS.pop();

                if(visited[row][col])
                    continue;

                visited[row][col] = true;

                for(int i = 0; i < 4; i++){
                    int newRow = row + dr[i];
                    int newCol = col + dc[i];

                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && matrix[newRow][newCol] == color){
                        BFS.push({newRow, newCol});
                    }
                }
            }

            count++;
        }
    }

    return count;
}

int main()
{
    int n;
    int count = 0;
    cin >> n;

    vector<vector<char>> matrix(n, vector<char> (n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    cout << countArea(matrix) << ' ';

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 'G')
                matrix[i][j] = 'R';
        }
    }

    cout << countArea(matrix);

    return 0;
}
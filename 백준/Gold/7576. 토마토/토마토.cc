#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    int count = 0; //안 익은 토마토 수
    int day = 0; //지난 일수

    cin >> m >> n;

    vector<vector<int>> tomatoes(n, vector<int>(m));
    queue<pair<int, int>> BFS;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> tomatoes[i][j];
            if(tomatoes[i][j] == 1)
                BFS.push(pair(i, j));
            else if (tomatoes[i][j] == 0)
                count++;
        }
    }

    int dr[] = {-1, 0, 0, 1};
    int dc[] = {0, -1, 1, 0};

    while(!BFS.empty()){
        auto[r, c] = BFS.front();
        BFS.pop();

        day = tomatoes[r][c];

        for(int i = 0; i < 4; i++){
            int new_r = r + dr[i];
            int new_c = c + dc[i];

            if(new_r >= 0 && new_r < n && new_c >= 0 && new_c < m && tomatoes[new_r][new_c] == 0){
                BFS.push(pair(new_r, new_c));
                tomatoes[new_r][new_c] = day + 1;
                count--;
            }
        }
    }

    cout << (count == 0 ? day - 1 : -1);

    return 0;
}
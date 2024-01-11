#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    int count = 0;
    cin >> n >> m;

    vector<vector<char>> matrix(n, vector<char>(m));
    pair<int, int> startNode;
    queue<pair<int, int>> BFS;

    //입력
    for(int r = 0; r < n; r++){
        string temp;
        cin >> temp;

        for(int c = 0; c < temp.size(); c++){
            matrix[r][c] = temp[c];
            if(matrix[r][c] == 'I')
                startNode = {r, c};
        }
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    BFS.push(startNode);

    while(!BFS.empty()){
        auto [r, c] = BFS.front();
        BFS.pop();

        if(matrix[r][c] == 'X')
            continue;

        if(matrix[r][c] == 'P')
            count++;

        matrix[r][c] = 'X';

        for(int i = 0; i < 4; i++){
            int newR = r + dr[i];
            int newC = c + dc[i];

            if(newR >= 0 && newR < n && newC >= 0 && newC <m && matrix[newR][newC] != 'X'){
                BFS.push({newR, newC});
            }
        }
    }

    if(count == 0) cout << "TT";
    else cout << count;

    return 0;
}
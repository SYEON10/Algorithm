#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


int main() {

    int n, m;
    cin >> n >> m;
    cin.ignore();

    vector<vector<int>> matrix(n + 2, vector<int>(m + 2, 0));
    queue<pair<int, int>> bfs;

    for(int row = 1; row <= n; row++){
        string input;
        getline(cin, input);
        for(int col = 1; col <= m; col++){
            matrix[row][col] = input[col - 1] - '0';
        }
    }
    bfs.push({1, 1});

    while(!bfs.empty()){
        pair<int, int> node = bfs.front();
        bfs.pop();

        if(node.first == n && node.second == m){
            break;
        }

        if(matrix[node.first - 1][node.second] == 1){
            bfs.push({node.first - 1, node.second});
            matrix[node.first - 1][node.second] = matrix[node.first][node.second] + 1;
        }
        if(matrix[node.first][node.second - 1] == 1){
            bfs.push({node.first, node.second - 1});
            matrix[node.first][node.second - 1] = matrix[node.first][node.second] + 1;
        }
        if(matrix[node.first + 1][node.second] == 1){
            bfs.push({node.first + 1, node.second});
            matrix[node.first + 1][node.second] = matrix[node.first][node.second] + 1;
        }
        if(matrix[node.first][node.second + 1] == 1){
            bfs.push({node.first, node.second + 1});
            matrix[node.first][node.second + 1] = matrix[node.first][node.second] + 1;
        }
    }

    cout << matrix[n][m];

    return 0;
}
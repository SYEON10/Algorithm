#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int countComplex = 1;
    vector<vector<int>> matrix(n, vector<int>(n));
    queue<pair<int, int>> BFS;
    vector<int> countHouse;

    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;

        for(int j = 0; j < n; j++){
            matrix[i][j] = temp[j] - '0';
        }
    }

    int dr[] = {0, 0,-1, 1};
    int dc[] = {-1, 1, 0, 0};

    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){

            if(matrix[row][col] == 1){
                int houses = 0;

                BFS.push({row, col});
                matrix[row][col] = countComplex + 1;

                while(!BFS.empty()){
                    auto [row, col] = BFS.front();
                    BFS.pop();

                    houses++;

                    for(int i = 0; i < 4; i++){
                        int newRow = row + dr[i];
                        int newCol = col + dc[i];

                        if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && matrix[newRow][newCol] == 1){
                            BFS.push({newRow, newCol});
                            matrix[newRow][newCol] = matrix[row][col];
                        }
                    }
                }

                countHouse.push_back(houses);
                countComplex++;
            }
        }
    }

    sort(countHouse.begin(), countHouse.end());

    cout << countComplex - 1 << '\n';

    for(int i = 0; i < countHouse.size(); i++){
        cout << countHouse[i] << '\n';
    }

    return 0;
}
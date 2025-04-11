#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e7;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, INF));
    vector<vector<int>> ans(n + 1, vector<int>(n + 1, INF));

    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        if(z < matrix[x][y]){
            matrix[x][y] = z;
            matrix[y][x] = z;
            ans[x][y] = y;
            ans[y][x] = x;
        }
    }

    for(int i = 1; i <= n; i++){
        matrix[i][i] = 0;
        ans[i][i] = i;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(matrix[i][j] > matrix[i][k] + matrix[k][j]){
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    ans[i][j] = k;
                }
            }
        }
    }
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j) continue;
                int current = ans[i][j];
                ans[i][j] = ans[i][current];
            }
        }
    }


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(ans[i][j] == i) cout << "- ";
            else cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
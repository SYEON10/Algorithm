#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 64e7 + 1;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, INF));

    for(int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;

        matrix[a][b] = min(matrix[a][b], c);
        matrix[b][a] = min(matrix[b][a], c);
    }

    for(int i = 1; i <= n; i++){
        matrix[i][i] = 0;
    }

    int v1, v2;
    cin >> v1 >> v2;

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    int a = matrix[1][v1] + matrix[v1][v2] + matrix[v2][n];
    int b = matrix[1][v2] + matrix[v2][v1] + matrix[v1][n];

    if(a > b){
        if(b >= INF) cout << -1;
        else cout << b;
    }
    else{
        if(a >= INF) cout << -1;
        else cout << a;
    }

    return 0;
}
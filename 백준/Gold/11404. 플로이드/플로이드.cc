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

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        matrix[a][b] = min(matrix[a][b], c);
    }

    for(int i = 1; i <= n; i++){
        matrix[i][i] = 0;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(matrix[i][j] == INF) cout << 0 << ' ';
            else cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
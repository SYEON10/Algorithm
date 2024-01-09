#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, c, n;
    cin >> a >> b >> c >> n;

    vector<vector<int>> test(n, vector<int> (4));
    vector<int> components(a + b + c + 1, 2);

    for(int i = 0; i < n ; i++){
        for(int j = 0; j < 4; j++){
            cin >> test[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        if(test[i][3] == 1){
            for(int j = 0; j < 3; j++){
                components[test[i][j]] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(test[i][3] != 1){
            int normal = 0;

            for(int j = 0; j < 3; j++){
                if(components[test[i][j]] == 1){
                    normal++;
                }
            }

            if(normal == 2){
                for(int j = 0; j < 3; j++){
                    if(components[test[i][j]] == 2){
                        components[test[i][j]] = 0;
                    }
                }
            }
        }
    }

    for(int i = 1; i <= a + b + c; i++){
        cout << components[i] << '\n';
    }

    return 0;
}
//
// Created by syeon on 2023-11-01.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, m, count = 0;
    string temp;
    cin >> n >> m;

    vector<string> A(n);
    vector<string> B(n);

    for(int row = 0; row < n; row++){
        cin >> A[row];
    }

    for(int row = 0; row < n; row++){
        cin >> B[row];
    }

    for(int row = 0; row < n - 2; row++){ //뒤집을 수 있는 범위 이동
        for(int col = 0; col < m - 2; col++){

            if(A[row][col] != B[row][col]){
                //뒤집기
                for(int _row = row; _row < row + 3; _row++){
                    for(int _col = col; _col < col + 3; _col++){
                        if(A[_row][_col] == '0'){
                            A[_row][_col] = '1';
                        }
                        else A[_row][_col] = '0';
                    }
                }

                count++;
            }
        }
    }

    if(A != B){
        cout << -1;
    }
    else cout << count;

    return 0;
}
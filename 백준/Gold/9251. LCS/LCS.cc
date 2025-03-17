#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//LCS

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    //r, c 해당 길이까지의 최장 공통 부분 길이
    vector<vector<int>> DP(str2.length() + 1, vector<int>(str1.length() + 1, 0));;

    //같으면 북서 + 1, 다르면 max(북, 서)
    for(int r = 1; r <= str2.length(); r++){
        for(int c = 1; c <= str1.length(); c++){
            if(str2[r-1] == str1[c-1]) {
                DP[r][c] = DP[r-1][c-1] + 1;
                continue;
            }
            DP[r][c] = max(DP[r-1][c], DP[r][c-1]);
        }
    }

    cout << DP[str2.length()][str1.length()];

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//LCS

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    //r, c 해당 길이까지의 최장 공통 부분 길이
    vector<vector<int>> DP(str2.length() + 1, vector<int>(str1.length() + 1, 0));;
    int size = max(str1.length(), str2.length());

    //같으면 북서 + 1, 다르면 max(북, 서)
    for (int r = 1; r <= str2.length(); r++) {
        for (int c = 1; c <= str1.length(); c++) {
            if (str2[r - 1] == str1[c - 1]) {
                DP[r][c] = DP[r - 1][c - 1] + 1;
                continue;
            }
            DP[r][c] = max(DP[r - 1][c], DP[r][c - 1]);
        }
    }

    int count = DP[str2.length()][str1.length()];
    queue<pair<int, int>> bfs;
    vector<char> ans(count);

    bfs.push({ str2.length(), str1.length()});
    int i = 0;

    while (i < count && !bfs.empty()) {
        int r = bfs.front().first;
        int c = bfs.front().second;
        bfs.pop();
        if (str2[r - 1] == str1[c - 1]) {
            ans[i] = str2[r - 1];
            i++;
            bfs.push({ r - 1, c - 1 });
            continue;
        }
        if (DP[r - 1][c] >= DP[r][c - 1]) {
            bfs.push({ r - 1, c });
            continue;
        }
        if (DP[r - 1][c] <= DP[r][c - 1]) {
            bfs.push({ r, c - 1 });
        }
    }

    cout << count << '\n';

    for (int i = count - 1; i >= 0; i--) {
        cout << ans[i];
    }

    return 0;
}
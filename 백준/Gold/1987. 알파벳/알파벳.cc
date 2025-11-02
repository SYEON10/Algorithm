#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//확신의 DFS

const int MAX = 21;

int n, m;
int result = 0;
string board[21];
bool alphabet[26];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void DFS(int x, int y, int count){
    if(count == n * m){
        result = count;
        return;
    }
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        if(alphabet[board[ny][nx] - 'A']) {
            result = max(result, count);
            continue;
        }
        alphabet[board[ny][nx] - 'A'] = true;
        DFS(nx, ny, count + 1);
        alphabet[board[ny][nx] - 'A'] = false;
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> board[i];
    }

    alphabet[board[0][0] - 'A'] = true;
    DFS(0, 0, 1);
    cout << result;

    return 0;
}
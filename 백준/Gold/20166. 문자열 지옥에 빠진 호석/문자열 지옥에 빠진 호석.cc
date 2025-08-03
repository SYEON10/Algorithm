#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int SIZE = 10;

int dr[8] = {1, 0, 0, -1, 1, 1, -1, -1};
int dc[8] = {0, 1, -1, 0, 1, -1, -1, 1};

char board[SIZE][SIZE];

int n, m, k;

unordered_map<string, int> strCount;

void DFS(int r, int c, int len, string str){
    if(len > 5) return;
    strCount[str]++;

    for(int i = 0; i < 8; i++){
        int nr = ((r + dr[i]) % n + n) % n;
        int nc = ((c + dc[i]) % m + m) % m;
        DFS(nr, nc, len + 1, str + board[nr][nc]);
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> m >> k;
    
    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            cin >> board[r][c];
        }
    }

    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            DFS(r, c, 1, string(1, board[r][c]));
        }
    }

    string input;
    for(int i = 0; i < k; i++){
        cin >> input;
        cout << strCount[input] << '\n';
    }

    return 0;
}
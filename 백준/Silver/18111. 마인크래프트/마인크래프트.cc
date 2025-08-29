#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//땅의 높이가 256으로 제한 -> 땅의 높이를 설정하고 그때 소요되는 비용 산정
//256 * N * M => N, M이 둘 다 500 이하이므로 O(N^2) 가능

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, m, b;
    cin >> n >> m >> b;

    int board[n][m];

    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            cin >> board[r][c];
        }
    }

    int min_time = INT32_MAX;
    int height = 0;
    for(int i = 0; i <= 256; i++){
        int timer = 0;
        int block = b;
        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                if(board[r][c] > i) {
                    timer += (board[r][c] - i) * 2;
                    block += board[r][c] - i;
                }
                if(board[r][c] < i) {
                    timer += i - board[r][c];
                    block -= i - board[r][c];
                }
            }
        }
        if(block < 0) continue;
        if(min_time >= timer){
            min_time = timer;
            height = i;
        }
    }

    cout << min_time << ' ' << height;

    return 0;
}
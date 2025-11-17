#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m, h;
int result = 5;
vector<vector<bool>> ladder;

bool CheckLadder() {
    int curr_c = 1;

    for (int c = 1; c < n; c++) {
        curr_c = c;
        for (int r = 1; r < h + 1; r++) {
            if (ladder[r][curr_c] == true) {
                curr_c++;
                continue;
            }
            if (ladder[r][curr_c - 1] == true) {
                curr_c--;
            }
        }
        if (curr_c != c) return false;
    }
    return true;
}

/// @param count = 추가할 사다리 개수
void BackTracking(int count, int index) {
    if (CheckLadder()) {
        result = min(result, count);
        return;
    }

    if (count == 3) {
        return;
    }

    for(int i = index; i < h * (n - 1); i++){
        int r = i / (n - 1) + 1;
        int c = i % (n - 1) + 1;
        if ((ladder[r][c] || ladder[r][c - 1] || ladder[r][c + 1])) {
            continue;
        }

        ladder[r][c] = true;
        BackTracking(count + 1, i + 1);
        ladder[r][c] = false;
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> h;

    ladder.assign(h + 1, vector<bool>(n + 1, false));

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        ladder[a][b] = true;
    }

    BackTracking(0, 0);

    if(result == 5) cout << -1;
    else cout << result;

    return 0;
}
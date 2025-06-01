#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int COUNT = 3;
int n;
vector<vector<int>> board;
vector<vector<bool>> visited;
vector<int> cost(COUNT, 0);
int sum = 0;
int min_cost = INT32_MAX;

vector<pair<int, int>> dir = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {0, 0} };

int CalculateCost(int r, int c) {
    int cost = 0;
    for (auto& d : dir) {
        cost += board[r + d.first][c + d.second];
    }
    return cost;
}

void UpdateVisited(int r, int c, bool check) {
    for (auto& d : dir) {
        visited[r + d.first][c + d.second] = check;
    }
}

bool CheckVisited(int r, int c) {
    for (auto& d : dir) {
        if (visited[r + d.first][c + d.second]) return false;
    }
    return true;
}

void BackTracking(int i) {
    if (sum >= min_cost) {
        return;
    }
    //이미 max 코스트를 넘겼다면 패스
    if (i == 3) {
        min_cost = sum;
        return;
    }

    for (int r = 1; r < n - 1; r++) {
        for (int c = 1; c < n - 1; c++) {
            if (!CheckVisited(r, c)) continue;
            UpdateVisited(r, c, true);
            cost[i] = CalculateCost(r, c);
            sum += cost[i];
            BackTracking(i + 1);
            sum -= cost[i];
            UpdateVisited(r, c, false);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    board.assign(n, vector<int>(n));
    visited.assign(n, vector<bool>(n, false));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cin >> board[r][c];
        }
    }

    BackTracking(0);

    cout << min_cost;

    return 0;
}
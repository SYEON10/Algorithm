#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int END = 100;

struct point {
    int x;
    int y;
};


point getNextPoint(point c, int d) {
    switch (d) {
    case 0:
        return point{ c.x + 1, c.y };
    case 1:
        return point{ c.x, c.y - 1 };
    case 2:
        return point{ c.x - 1, c.y };
    case 3:
        return point{ c.x, c.y + 1 };
    }
    return point{ 0, 0 };
}

int rotate(int direction) {
    return (direction + 1) % 4;
}

void dragonCurve(point data, int direction, int generation, vector<vector<bool>>& board) {
    vector<int> route = { direction };

    board[data.x][data.y] = true;
    data = getNextPoint(data, direction);
    board[data.x][data.y] = true;

    for (int i = 1; i <= generation; i++) {
        int size = route.size();
        for (int j = size - 1; j >= 0; j--) {
            int d = rotate(route[j]);
            route.push_back(d);
            data = getNextPoint(data, d);
            board[data.x][data.y] = true;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<bool>> board(END + 1, vector<bool>(END + 1, false));

    for (int i = 0; i < n; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        dragonCurve(point{ x, y }, d, g, board);
    }

    int count = 0;

    for (int i = 0; i < END; i++) {
        for (int j = 0; j < END; j++) {
            if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) {
                count++;
            }
        }
    }

    cout << count;

    return 0;
}
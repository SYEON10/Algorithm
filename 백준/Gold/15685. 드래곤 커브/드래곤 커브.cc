#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int END = 100;
const int MAX_GEN = 10;

struct curve {
    int x;
    int y;
};

vector<vector<bool>> dragonCurve;

curve GetNextCurve(curve c, int d) {
    switch (d) {
    case 0:
        return curve{ c.x + 1, c.y };
    case 1:
        return curve{ c.x, c.y - 1 };
    case 2:
        return curve{ c.x - 1, c.y };
    case 3:
        return curve{ c.x, c.y + 1 };
    }
    return curve{ 0, 0 };
}

int Rotate(int direction) {
    return (direction + 1) % 4;
}

void DragonCurve(curve data, int direction, int generation) {
    vector<int> route;
    route.push_back(direction);
    dragonCurve[data.x][data.y] = true;

    data = GetNextCurve(data, direction);
    dragonCurve[data.x][data.y] = true;

    for (int i = 1; i <= generation; i++) {
        int current_route = route.size();
        for (int j = current_route - 1; j >= 0; j--) {
            int d = Rotate(route[j]);
            route.push_back(d);
            data = GetNextCurve(data, d);
            dragonCurve[data.x][data.y] = true;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    dragonCurve.assign(END + 1, vector<bool>(END + 1, false));

    for (int i = 0; i < n; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        DragonCurve(curve{ x, y }, d, g);
    }

    int count = 0;

    for (int i = 0; i < END; i++) {
        for (int j = 0; j < END; j++) {
            if (dragonCurve[i][j] && dragonCurve[i + 1][j] && dragonCurve[i][j + 1] && dragonCurve[i + 1][j + 1]) {
                count++;
            }
        }
    }

    cout << count;

    return 0;
}
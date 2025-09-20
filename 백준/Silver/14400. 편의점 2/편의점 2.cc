#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<pair<int,int>> points(n);
    vector<int> xs(n), ys(n);

    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
        xs[i] = points[i].first;
        ys[i] = points[i].second;
    }

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    int mid_x = xs[n/2];
    int mid_y = ys[n/2];

    long long result = 0;
    for (int i = 0; i < n; i++) {
        result += abs(points[i].first - mid_x) + abs(points[i].second - mid_y);
    }

    cout << result;
    return 0;
}

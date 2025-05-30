#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

const float INF = 1e6;

struct Point{
    float x, y;
};


float Distance(const Point& a, const Point& b){
    return hypot(b.x - a.x, b.y - a.y);
}

float Prim(const int n, const vector<Point>& points){
    vector<float> distance(n, INF);
    priority_queue<pair<float, int>, vector<pair<float, int>>, greater<>> pq;

    vector<bool> visited(n);

    pq.push({0, 0});
    distance[0] = 0;

    float sum = 0;

    while(!pq.empty()){
        float weight = pq.top().first;
        int index = pq.top().second;
        Point node = points[index];
        pq.pop();

        if(visited[index]) continue;
        visited[index] = true;
        sum += weight;

        for(int i = 0; i < points.size(); i++){
            if(!visited[i] && distance[i] > Distance(node, points[i])){
                distance[i] = Distance(node, points[i]);
                pq.push({distance[i], i});
            }
        }
    }

    return sum;
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    vector<Point> stars(n);

    float x, y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        stars[i] = Point{x, y};
    }

    cout << std::fixed << std::setprecision(2);
    cout << Prim(n, stars);
    
    return 0;
}
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
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<vector<bool>> visited(n, vector<bool>(n, false));

    //이전에 같은 노드로 방문했다면 다시 방문할 필요가 없음
    //그리고... weight가 낮은? 게 필요한가? 어차피 가중치 저장이 필요없는데?

    pq.push({0, 0});
    distance[0] = 0;

    while(!pq.empty()){
        float weight = pq.top().first;
        int index = pq.top().second;
        Point node = points[index];
        pq.pop();

        if(distance[index] < weight) continue;

        for(int i = 0; i < points.size(); i++){
            if(i == index) continue;
            if(!visited[index][i] && distance[i] > Distance(node, points[i])){
                distance[i] = Distance(node, points[i]);
                pq.push({distance[i], i});
                visited[index][i] = true;
                visited[i][index] = true;
            }
        }
    }

    float count = 0;
    for(float d : distance){
        count += d;
    }

    return count;
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
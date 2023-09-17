#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point{
    int x;
    int y;
};

bool cmp(point a, point b){
    if(a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}

int main(){

    int n, x, y;
    cin >> n;

    vector<point> v;
    point p;

    for(int i = 0; i < n; i++){
        cin >> x >> y;
        p = {x,y};
        v.push_back(p);
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < n; i++){
        cout << v[i].x << " " << v[i].y << "\n";
    }


    return 0;
}
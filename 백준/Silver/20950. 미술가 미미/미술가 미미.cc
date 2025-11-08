#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

struct Color{
    int r, g, b;
};

int n;
int min_diff = __INT32_MAX__;
Color c[31];
Color m_color;
Color color = {0, 0, 0};

//2개 이상 7개 이하 조합을 구하는 백트래킹

void backTracking(int count, int start){
    if(count > 7) return;
    if(count >= 2){
        min_diff = min(min_diff, abs(m_color.r - (color.r / count)) + abs(m_color.g - (color.g / count)) + abs(m_color.b - (color.b / count)));
    }
    
    for(int i = start + 1; i < n; i++){
        color.r += c[i].r;
        color.g += c[i].g;
        color.b += c[i].b;
        backTracking(count + 1, i);
        color.r -= c[i].r;
        color.g -= c[i].g;
        color.b -= c[i].b;
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> c[i].r >> c[i].g >> c[i].b;
    }
    cin >> m_color.r >> m_color.g >> m_color.b;


    backTracking(0, -1);

    cout << min_diff;

    return 0;
}
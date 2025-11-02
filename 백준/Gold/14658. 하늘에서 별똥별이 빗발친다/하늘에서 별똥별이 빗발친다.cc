#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//특정 별똥별이 트램펄린의 오른쪽 위인 경우 완탐 => 불가능.
//O(n^2) n = 100

typedef pair<int, int> point;

int countStars(int r, int c, const vector<point>& stars, int l){
        int count = 0;
        for(point check : stars){
            if(r <= check.first 
                && check.first <= r + l 
                && c <= check.second 
                && check.second <= c + l){
                    count++;
                }
        }
        return count;
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, m, l, k;
    int result = 0;
    cin >> n >> m >> l >> k;

    vector<point> stars(k);

    for(int i = 0; i < k; i++){
        cin >> stars[i].first >> stars[i].second;
    }

    for(point r : stars){
        for(point c : stars){
            result = max(result, countStars(r.first, c.second, stars, l));
        }
    }

    cout << k - result;

    return 0;
}
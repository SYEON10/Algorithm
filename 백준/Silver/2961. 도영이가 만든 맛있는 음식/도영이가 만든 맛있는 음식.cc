#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int n;
vector<pair<int, int>> ings;
int sint = 1;
int sun = 0;
int min_taste = INT_MAX;

//중복x 오름차순 순열
void back(int last){
    if(last != -1){
        min_taste = min(min_taste, abs(sint - sun));
    }

    for(int i = last + 1; i < ings.size(); i++){
        sint *= ings[i].first;
        sun += ings[i].second;
        back(i);
        sint /= ings[i].first;
        sun -= ings[i].second;
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        pair<int, int> p;
        cin >> p.first >> p.second;
        ings.push_back(p);
    }

    back(-1);

    cout << min_taste;

    return 0;
}
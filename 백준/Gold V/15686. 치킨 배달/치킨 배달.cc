#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;

int ans = INT_MAX;

int houseCount = 0;
int chickenCount = 0;

pair<int, int> chicken[13];
pair<int, int> house[100];
bool checker[13];

void ChickenLen(){
    int result = 0;
    for(int h = 0; h < houseCount; h++){
        int cLen = INT_MAX;
        for(int c = 0; c < chickenCount; c++){
            if(checker[c]){
                int len = abs(house[h].first - chicken[c].first) + abs(house[h].second - chicken[c].second);
                cLen = min(len, cLen);
            }
        }
        result += cLen;
    }

    ans = ans > result ? result : ans;
}

void Backtracking1(int count, int start){
    if(count == m){
        ChickenLen();
        return;
    }

    for(int i = start; i < chickenCount; i++){
        if(!checker[i]){
            checker[i] = true;
            Backtracking1(count + 1, i);
            checker[i] = false;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            int x;
            cin >> x;
            if(x == 2){
                chicken[chickenCount] = {r, c};
                chickenCount++;
            }
            if(x == 1){
                house[houseCount] = {r, c};
                houseCount++;
            }
        }
    }
        
    Backtracking1(0, 0);

    cout << ans;

    return 0;
}
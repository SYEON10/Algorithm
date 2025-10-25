#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    vector<int> heights(9);

    for(int i = 0; i < 9; i++){
        cin >> heights[i];
    }

    sort(heights.begin(), heights.end());

    vector<int> v(9, 0);
    for(int i = 8; i > 1; i--){
        v[i] = 1;
    }

    do{
        int count = 0;
        for(int i = 0; i < 9; i++){
            if(v[i] == 0) continue;
            count += heights[i];
        }
        if(count == 100){
            for(int i = 0; i < 9; i++){
                if(v[i] == 0) continue;
                cout << heights[i] << '\n';
            }
            return 0;
        }
    }
    while(next_permutation(v.begin(), v.end()));

    return 0;
}
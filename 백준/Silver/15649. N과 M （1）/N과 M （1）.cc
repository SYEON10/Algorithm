#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

//중복 없이 M개를 고른 수열 => 순열 구하기!

int n, m;
vector<bool> visited;
vector<int> arr;

void back(int cnt){
    if(cnt == m){
        for(int i : arr){
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;
        visited[i] = true;
        arr[cnt] = i; 
        back(cnt + 1);
        visited[i] = false;
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> m;

    visited.assign(n + 1, false);
    arr.assign(m, 0);

    back(0);

    return 0;
}
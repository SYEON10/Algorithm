#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int n = 3;
vector<int> board(n * n);
vector<int> magic(n * n);
int res = INT_MAX;

//1~9까지 중복순열(순서가 다르면 다른 것)

int calculator(){
    int sum = 0;
    int curr = 0;

    for(int i = 0; i < n; i++){
        sum += magic[i];
    }

    for(int i = 0; i < n; i++){
        int index = i * n + i;
        curr += magic[index];
    }

    if(curr != sum) return INT_MAX;

    curr = 0;
    for(int i = 0; i < n; i++){
        int index = i * n + (n - 1 - i);
        curr += magic[index];
    }

    if(curr != sum) return INT_MAX;

    for(int r = 0; r < n; r++){
        int curr = 0;
        for(int c = 0; c < n; c++){
            int index = r * n + c;
            curr += magic[index];
        }
        if(curr != sum) return INT_MAX;
    }

    for(int c = 0; c < n; c++){
        int curr = 0;
        for(int r = 0; r < n; r++){
            int index = r * n + c;
            curr += magic[index];
        }
        if(curr != sum) return INT_MAX;
    }

    int result = 0;

    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            int index = r * n + c;
            result += abs(board[index] - magic[index]);
        }
    }

    return result;
}

vector<bool> visited(10, false);

void back(int cnt){
    if(cnt == 9){
        res = min(res, calculator());
        return;
    }
    for(int i = 1; i <= n * n; i++){
        if(visited[i]) continue;
        visited[i] = true;
        magic[cnt] = i;
        back(cnt + 1);
        visited[i] = false;
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    for(int i = 0; i < n * n; i++){
        cin >> board[i];
    }

    back(0);

    cout << res;

    return 0;
}
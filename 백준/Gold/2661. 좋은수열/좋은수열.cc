#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int n;
vector<int> answer;

bool Simulate(int curr){
    if(curr < 4) return false;
    for(int i = curr - 2; curr - i < i + 1; i--){
        if(answer[curr] == answer[i]){
            bool passed = true;
            for(int j = curr; j > i; j--){
                if(answer[j] != answer[j - (curr - i)]) {
                    passed = false;
                    break;
                }
            }
            if(passed) return true;
        }
    }

    return false;
}

bool Back(int count){
    if(Simulate(count - 1)){
        return false;
    }
    if(count == n + 1){
        return true;
    }
    for(int i = 1; i <= 3; i++){
        if(answer[count - 1] == i) continue;
        answer[count] = i;
        if(Back(count + 1)) return true;
    }

    return false;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n;

    answer.assign(n + 1, 0);

    Back(1);

    for(int i = 1; i <= n; i++){
        cout << answer[i];
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    stack<pair<int, int>> stk;

    for(int i = 1; i <= n; i++){
        int input;
        cin >> input;

        while(!stk.empty() && input > stk.top().first){
            stk.pop();
        }

        if(stk.empty()) cout << 0 << ' ';
        else cout << stk.top().second << ' ';
        
        stk.push({input, i});
    }

    return 0;
}
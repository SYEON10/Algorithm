#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> num(n + 1);
    stack<int> monoStack;

    for(int i = 1; i <= n; i++){
        cin >> num[i];
    }

    monoStack.push(num[n]);
    num[n] = -1;

    for(int i = n - 1; i > 0; i--){
        while(!monoStack.empty() && monoStack.top() <= num[i]){
            monoStack.pop();
        }

        int top = -1;
        if(!monoStack.empty()) top = monoStack.top();

        monoStack.push(num[i]);
        num[i] = top;
    }

    for(int i = 1; i <= n; i++){
        cout << num[i] << ' ';
    }
    
    return 0;
}
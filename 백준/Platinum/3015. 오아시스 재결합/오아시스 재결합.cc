#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    long long count = 0;
    stack<pair<int, int>> stk;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        int dup = 0;
        while (!stk.empty() && input >= stk.top().first) {
            if (input == stk.top().first) dup = stk.top().second;
            count += stk.top().second;
            stk.pop();
        }
        if (!stk.empty()) {
            count += 1;
        }

        stk.push({ input, dup + 1 });
    }

    cout << count;

    return 0;
}
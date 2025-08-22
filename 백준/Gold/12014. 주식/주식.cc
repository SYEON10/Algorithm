#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int t;
    cin >> t;

    for(int c = 1; c <= t; c++){
        int n, k;
        cin >> n >> k;

        int LIS[n] = {};
        int end = 0;

        for(int i = 0; i < n; i++){
            int x;
            cin >> x;

            if(x > LIS[end]){
                LIS[end + 1] = x;
                end++;
                continue;
            }

            *lower_bound(&LIS[0], &LIS[end], x) = x;
        }

        cout << "Case #" << c <<'\n';
        cout << int(end >= k) << '\n';
    }

    return 0;
}
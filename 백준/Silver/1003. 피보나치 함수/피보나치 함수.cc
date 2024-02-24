#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 40;
vector<int> DP_0(SIZE + 1, 0);
vector<int> DP_1(SIZE + 1, 0);
vector<int> DP_f(SIZE + 1, 0);

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        DP_f[n-1] = (DP_f[n-1] != 0) ? DP_f[n-1] : fibonacci(n-1);
        DP_f[n-2] = (DP_f[n-2] != 0) ? DP_f[n-2] : fibonacci(n-2);

        DP_0[n] = DP_0[n-1] + DP_0[n-2];
        DP_1[n] = DP_1[n-1] + DP_1[n-2];

        return DP_f[n-1] + DP_f[n-2];
    }
}

int main() {

    int t;
    cin >> t;

    DP_0[0] = 1;
    DP_0[1] = 0;
    DP_1[0] = 0;
    DP_1[1] = 1;

    while(t--){
        int n;
        cin >> n;
        fibonacci(n);
        cout << DP_0[n] << ' ' << DP_1[n] << '\n';
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    int maxDP[3] = {0, 0, 0};
    int minDP[3] = {0, 0, 0};

    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;

        int tempA = max(maxDP[0], maxDP[1]) + a;
        int tempB = max(max(maxDP[0], maxDP[1]), maxDP[2]) + b;
        int tempC = max(maxDP[1], maxDP[2]) + c;

        maxDP[0] = tempA;
        maxDP[1] = tempB;
        maxDP[2] = tempC;

        tempA = min(minDP[0], minDP[1]) + a;
        tempB = min(min(minDP[0], minDP[1]), minDP[2]) + b;
        tempC = min(minDP[1], minDP[2]) + c;

        minDP[0] = tempA;
        minDP[1] = tempB;
        minDP[2] = tempC;
    }

    cout << max(max(maxDP[0], maxDP[1]), maxDP[2]) << ' ';
    cout << min(min(minDP[0], minDP[1]), minDP[2]);
    
    return 0;
}
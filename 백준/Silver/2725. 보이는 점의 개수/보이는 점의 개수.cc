#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX = 1001;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int arr[MAX];

    arr[0] = 0;
    arr[1] = 3;

    for(int i = 2; i <= MAX; i++){
        int count = 0;
        for(int delta = 1; delta <= i; delta++){
            if(__gcd(delta, i) == 1) count++;
        }
        arr[i] = arr[i - 1] + count * 2;
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        cout << arr[n] << '\n';
    }

    return 0;
}
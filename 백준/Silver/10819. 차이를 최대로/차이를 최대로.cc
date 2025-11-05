#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int result = 0;
    do{
        int count = 0;
        for(int i = 0; i < n - 1; i++){
            count += abs(arr[i] - arr[i + 1]);
        }
        result = max(result, count);
    }
    while(next_permutation(arr.begin(), arr.end()));

    cout << result;

    return 0;
}
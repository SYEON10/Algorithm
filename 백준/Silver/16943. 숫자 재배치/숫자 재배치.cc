#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int a, b;

    cin >> a >> b;

    vector<int> num;

    while(a != 0){
        num.push_back(a % 10);
        a /= 10;
    }

    sort(num.begin(), num.end(), greater<>());

    int ans = -1;

    do{
        int comp = 0;
        if(num.back() == 0) continue;
        for(int i = num.size() - 1; i >= 0; i--){
            comp += num[i] * pow(10, i);
        }
        if(comp < b && comp != 0){
            ans = max(ans, comp);
        }
    }
    while(prev_permutation(num.begin(), num.end()));

    cout << ans;

    return 0;
}
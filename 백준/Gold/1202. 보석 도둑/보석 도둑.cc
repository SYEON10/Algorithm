#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int SIZE = 300000;

int bags[SIZE];
pair<int, int> jewel[SIZE];

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        int w, v;
        cin >> w >> v;

        jewel[i] = {v, w};
    }

    for(int i = 0; i < k; i++){
        cin >> bags[i];
    }

    sort(jewel, jewel + n, greater<>());
    sort(bags, bags + k, greater<>());

    multiset<int> ms(bags, bags + k);

    long long sum = 0;
    for(auto j : jewel){
        auto it = ms.lower_bound(j.second);
        if(it != ms.end()){
            sum += j.first;
            ms.erase(it);
        }
    }

    cout << sum;

    return 0;
}
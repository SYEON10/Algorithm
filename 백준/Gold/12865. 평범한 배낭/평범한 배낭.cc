#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct item {
    int weight;
    int value;
};

int main()
{
    int n, k;
    cin >> n >> k;

    vector<item> items(n);

    //i = 무게 value = 가치합
    vector<int> DP(k + 1, 0);

    for(int i = 0; i < n; i++){
        cin >> items[i].weight >> items[i].value;
    }

    for(int i = 0; i < n; i++){
        item item = items[i];
        for(int j = k; j >= item.weight; j--){
            DP[j] = max(DP[j], item.value + DP[j - item.weight]);
        }
    }

    cout << DP[k];

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long long Calculate(const vector<int>& table){
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    int n = table.size();
    long long ans = 0;

    for(int i = 0; i < n; i++){
        pq.push(table[i]);
    }

    while(pq.size() > 1){
        long long cost = pq.top();
        pq.pop();
        cost += pq.top();
        pq.pop();
        pq.push(cost);
        ans += cost;
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> table(n);
        for(int i = 0; i < n; i++){
            cin >> table[i];
        }

        cout << Calculate(table) << '\n';
    }

    return 0;
}
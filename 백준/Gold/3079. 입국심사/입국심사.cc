#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll max_judge(ll sec, const vector<ll>& judge){
    ll count = 0;
    for(ll time : judge){
        count += sec / time;
        // 오버플로우 방지: count가 m 이상이면 그만
        if (count >= 1e18) break;
    }
    return count;
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;

    vector<ll> judge(n);
    for(int i = 0; i < n; i++){
        cin >> judge[i];
    }  

    ll left = 1;
    ll right = *max_element(judge.begin(), judge.end()) * m;
    ll answer = right;

    while (left <= right) {
        ll mid = (left + right) / 2;
        ll value = max_judge(mid, judge);

        if (value < m) {
            left = mid + 1;
        } else {
            answer = mid;
            right = mid - 1;
        }
    }

    cout << answer << "\n";
    return 0;
}

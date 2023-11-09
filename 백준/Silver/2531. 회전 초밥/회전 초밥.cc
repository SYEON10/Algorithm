#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, d, k, c, ans;

    cin >> n >> d >> k >> c;

    vector<int> plates(n);
    vector<bool> ate(d + 1, false);

    for(auto &plate : plates){
        cin >> plate;
    }

    //윈도우 초기화
    int count = 0;
    for(int i = 0; i < k; i++){
        if(!ate[plates[i]]){
            ate[plates[i]] = true;
            count++;
        }
    }

    ans = count;

    if(!ate[c]){
        ans++;
    }

    //코너케이스 : 마지막
    for(int left = 1; left < n; left++){
        ate[plates[left - 1]] = false;
        count--;
        for(int i = 0; i < k; i++){
            if(!ate[plates[(left + i) % n]]){
                ate[plates[(left + i) % n]] = true;
                count++;
            }
        }
        if(!ate[c]){
            ans = max(ans, count + 1);
        }
        else ans = max(ans, count);
    }

    cout << ans;

    return 0;
}
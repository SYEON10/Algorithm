#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e4; //구역의 최대 인구 수 100 * N 10

int n;
int ans;
vector<int> weight;
vector<vector<int>> adj_list;
vector<bool> section;

//선거구의 인구수
int Population(vector<bool> sec, bool checker){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        if(sec[i] == checker){
            sum += weight[i];
        }
    }

    return sum;
}

//sections가 다 연결되어 있는지 체크
bool Check(vector<bool> sec, bool checker) {

    queue<int> BFS;

    for(int i = 1; i <= n; i++){
        if(sec[i] == checker){
            BFS.push(i);
            sec[i] = !checker;
            break;
        }
    }

    while(!BFS.empty()){
        int node = BFS.front();
        BFS.pop();

        for(int next : adj_list[node]){
            if(sec[next] != checker) continue;
            sec[next] = !checker;
            BFS.push(next);
        }
    }

    for(int i = 1; i <= n; i++){
        if(sec[i] == checker){
            return false;
        }
    }

    return true;
}

//조합 계산
void Combination(int cnt, int node) {
    if(cnt == 0){
        //for(int i = 1; i <= n; i++){
        //    if(section[i]) cout << i << ' ';
        //}
        //cout << '\n';

        if(Check(section, true) && Check(section, false)){
        //    cout << "Clear! \n";
            ans = min(ans, abs(Population(section, true) - Population(section, false)));
        }
        return;
    }
    for(int i = 2; i <= n; i++){
        if(i <= node) continue;
        section[i] = true;
        Combination(cnt - 1, i);
        section[i] = false;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ans = INF;

    cin >> n;

    weight.assign(n + 1, 0);
    adj_list.assign(n + 1, vector<int>());
    section.assign(n + 1, false);

    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
    }

    for (int i = 1; i <= n; i++) {
        int count = 0;
        cin >> count;
        for (int j = 0; j < count; j++) {
            int connected_node;
            cin >> connected_node;
            adj_list[i].push_back(connected_node);
        }
    }

    //중복 방지를 위해 한 수를 고정
    section[1] = true;
    for(int i = 0; i < n - 1; i++){
        Combination(i, 0);
    }

    if (ans == INF) cout << -1;
    else cout << ans;

    return 0;
}
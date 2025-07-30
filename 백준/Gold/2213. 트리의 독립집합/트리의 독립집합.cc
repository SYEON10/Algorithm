#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
vector<int> cost;
vector<vector<int>> adj_list;
vector<vector<int>> DP; // node가 우수마을일 때/아닐 때 최대 주민 수
vector<int> track; //이전 노드가 우수마을이 아닐 때 우수마을인지 아닌지
vector<int> route;

void Check(int node, int prev, int prevgood) {

    if (prevgood) {
        for (int next : adj_list[node]) {
            if (prev == next) continue;
            Check(next, node, 0);
        }
    }
    else {
        if(track[node]) route.push_back(node);

        for (int next : adj_list[node]) {
            if (prev == next) continue;
            Check(next, node, track[node]);
        }
    }
}

int DFS(int node, int prev, int good) {
    if (DP[node][good] != -1)
        return DP[node][good];

    if (good) {
        DP[node][good] = cost[node];
    }
    else DP[node][good] = 0;
    for (int next : adj_list[node]) {
        if (next == prev) continue;
        if (good) {
            DP[node][good] += DFS(next, node, 0);
        }
        else {
            int nextGood = DFS(next, node, 1);
            int nextBad = DFS(next, node, 0);
            if (nextGood >= nextBad) {
                DP[node][good] += nextGood;
                track[next] = 1;
            }
            else {
                DP[node][good] += nextBad;
                track[next] = 0;
            }
        }
    }

    return DP[node][good];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    cost.assign(n + 1, 0);
    DP.assign(n + 1, vector<int>(2, -1));
    track.assign(n + 1, -1);
    adj_list.assign(n + 1, vector<int>());

    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }

    int good = DFS(1, 0, 1);
    int bad = DFS(1, 0, 0);

    if (good > bad) {
        track[1] = 1;
        Check(1, 0, 0);
        cout << good << '\n';
    }
    else {
        track[1] = 0;
        Check(1, 0, 0);
        cout << bad << '\n';
    }

    sort(route.begin(), route.end());

    for (auto r : route) {
        cout << r << ' ';
    }
       
    return 0;
}
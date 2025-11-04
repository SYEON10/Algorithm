#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

//사이클이 발생하는 경우 = 집합
//근데 이거 발상을 혼자 풀었으면 평생 DFS 못 떠올림...
//"사이클"이 무엇을 의미하는지 좀 더 내재화 필요...

//Closed 여부 어떻게 판단하지;
//Closed = 만났던 애를 또 만나는 것

set<int> result;
vector<bool> visited;
vector<int> adj_list;

void DFS(int node){
    int next = adj_list[node];
    if(next == -1) return;
    visited[node] = true;
    if(result.find(next) != result.end()) return;
    if(visited[next]) {
        result.insert(next);
    }
    DFS(next);
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n;
    cin >> n;

    adj_list.assign(n + 1, -1);
    visited.assign(n + 1, false);

    for(int i = 1; i <= n; i++){
        cin >> adj_list[i];
    }

    for(int node = 1; node <= n; node++){
        for(int i = 1; i <= n; i++){
            visited[i] = false;
        }
        if(result.find(node) == result.end()){
            DFS(node);
        }
    }

    cout << result.size() << '\n';
    for(int i : result){
        cout << i << '\n';
    }
    return 0;
}
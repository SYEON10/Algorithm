#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct edge{
    int begin;
    int end;
    int weight;
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<edge> edges(m);
    vector<long long> distance(n + 1, INF);

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = edge{u, v, w};
    }

    distance[1] = 0;
    bool negCycle = false;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            edge e = edges[j];

            if(distance[e.begin] == INF) continue;

            if(distance[e.end] > distance[e.begin] + e.weight){
                distance[e.end] = distance[e.begin] + e.weight;
                if(i == n - 1){
                    negCycle = true;
                    break;
                }
            }
        }
    }

    if(negCycle) {
        cout << -1;
        return 0;
    }
    else{
        for(int i = 2; i <= n; i++){
            if(distance[i] == INF) cout << -1 << '\n';
            else cout << distance[i] << '\n';
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//2500 * 2 * 10,000
const int INF = 5e7;

struct edge{
    int start;
    int end;
    int weight;
};

bool BellmanFord(const vector<edge>& adj_list, const int n){

        vector<int> distance(n + 1, INF);
        distance[1] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < adj_list.size(); j++){
                int start = adj_list[j].start;
                int end = adj_list[j].end;
                int weight = adj_list[j].weight;
    
                //if(distance[start] == INF) continue;
                if(distance[start] + weight < distance[end]){
                    distance[end] = distance[start] + weight;
                    if(i == n - 1) return false;
                }
            }
        }

    return true;
}

int main()
{
    int t;
    cin >> t;

    while(t--){
        int n, m, w;
        cin >> n >> m >> w;

        vector<edge> adj_list;

        for(int i = 0; i < m; i++){
            int s, e, t;
            cin >> s >> e >> t;

            adj_list.push_back(edge{s, e, t});
            adj_list.push_back(edge{e, s, t});
        }

        for(int i = 0; i < w; i++){
            int s, e, t;
            cin >> s >> e >> t;
            adj_list.push_back(edge{s, e, -t});
        }

        if(BellmanFord(adj_list, n)) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    int count = 0;
    cin >> n >> m;

    vector<vector<int>> adjList(n + 1, vector<int>());
    vector<bool> visited(n + 1, false);
    queue<int> BFS;

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    for(int i = 1; i <= n; i++){

        if(visited[i])
            continue;

        BFS.push(i);
        count++;

        while(!BFS.empty()){
            int node = BFS.front();
            BFS.pop();

            if(visited[node])
                continue;

            visited[node] = true;

            for(int i = 0; i < adjList[node].size();i++){
                int nextNode = adjList[node][i];
                if(!visited[nextNode]){
                    BFS.push(nextNode);
                }
            }
        }
    }

    cout << count;

    return 0;
}
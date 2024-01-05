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
    vector<int> visited(n + 1, false);
    queue<int> BFS;

    for(int i = 0; i < m; i++){
        int first, second;
        cin >> first >> second;

        //쌍방향
        adjList[first].push_back(second);
        adjList[second].push_back(first);
    }

    BFS.push(1);

    while(!BFS.empty()){
        int node = BFS.front();
        BFS.pop();

        if(visited[node])
            continue;

        visited[node] = true;
        count++;

        for(int i = 0; i < adjList[node].size(); i++){
            int check = adjList[node][i];
            if(!visited[check])
                BFS.push(check);
        }
    }

    cout << count - 1;

    return 0;
}
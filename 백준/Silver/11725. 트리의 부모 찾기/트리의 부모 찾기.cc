#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> adjList(n + 1, vector<int>());
    vector<int> visited(n + 1, false);
    vector<int> order(n + 1);
    queue<int> BFS;

    for(int i = 0; i < n - 1; i++){
        int first, second;
        cin >> first >> second;

        adjList[first].push_back(second);
        adjList[second].push_back(first);
    }

    BFS.push(1);
    visited[1] = true;

    while(!BFS.empty()){
        int node = BFS.front();
        BFS.pop();

        for(int i = 0; i < adjList[node].size(); i++){
            int check = adjList[node][i];
            if(!visited[check]){
                BFS.push(check);
                order[check] = node;
                visited[node] = true;
            }
        }
    }

    for(int i = 2; i <= n; i++){
        cout << order[i] << '\n';
    }

    return 0;
}
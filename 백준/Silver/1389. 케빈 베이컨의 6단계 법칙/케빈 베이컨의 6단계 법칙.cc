#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    //key - user, value - adjList
    vector<vector<int>> users(n + 1, vector<int>());
    //key - user, value = kevin num
    vector<int> kevinNum(n + 1);
    queue<int> BFS;
    int result = 0;
    kevinNum[result] = INT_MAX;

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        users[x].push_back(y);
        users[y].push_back(x);
    }

    for(int i = 1; i <= n; i++){
        vector<int> visited(n + 1, 0);
        BFS.push(i);

        while(!BFS.empty()){
            int node = BFS.front();
            BFS.pop();

            for(int j = 0; j < users[node].size(); j++){
                int newNode = users[node][j];

                if(visited[newNode] == 0){
                    visited[newNode] = visited[node] + 1;
                    BFS.push(newNode);
                }
            }
        }

        for(int j = 1; j < visited.size(); j++){
            kevinNum[i] += visited[j];
        }

        if(kevinNum[result] > kevinNum[i]){
            result = i;
        }
    }

    cout << result;

    return 0;
}

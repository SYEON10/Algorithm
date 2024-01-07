#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100000;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> visited(MAX * 2, 0);
    queue<int> BFS;

    BFS.push(n);

    while(!BFS.empty()){
        int node = BFS.front();
        BFS.pop();

        if(k == node){
            cout << visited[node];
            break;
        }

        int check[] = {node + 1, node - 1, node * 2};

        for(int i = 0; i < 3; i++){
            if(check[i] >= 0 && check[i] <= MAX * 2 && !visited[check[i]]){
                BFS.push(check[i]);
                visited[check[i]] = visited[node] + 1;
            }
        }
    }

    return 0;
}
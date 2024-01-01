#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


//스택
void DFS(const vector<vector<bool>>& AdjMatrix, int StartNode){
    stack<int> temp;
    vector<bool> checker(AdjMatrix.size() + 1, false);
    vector<int> order;

    temp.push(StartNode);

    while(!temp.empty()){
        int node = temp.top();
        temp.pop();

        if(checker[node])
            continue;
        order.push_back(node);
        checker[node] = true;

        for(int i = AdjMatrix.size(); i > 0; i--){
            //연결되어있고 방문기록이 없다면
            if(!AdjMatrix[node][i] || checker[i]) {
                continue;
            }
            temp.push(i);
        }
    }

    for(int value : order){
        cout << value << " ";
    }
}

//큐
void BFS(const vector<vector<bool>>& AdjMatrix, int StartNode){
    queue<int> temp;
    vector<bool> checker(AdjMatrix.size() + 1, false);
    vector<int> order;

    temp.push(StartNode);
    checker[StartNode] = true;

    while(!temp.empty()){
        int node = temp.front();
        order.push_back(node);
        temp.pop();

        for(int i = 1; i <= AdjMatrix.size(); i++){
            //연결되어있고 방문기록이 없다면
            if(!AdjMatrix[node][i] || checker[i]){
                continue;
            }
            temp.push(i);
            checker[i] = true;
        }
    }

    for(int value : order){
        cout << value << " ";
    }
}

int main()
{
    int n, m, v, x, y;
    cin >> n >> m >> v;

    vector<vector<bool>> AdjMatrix(n + 1, vector<bool>(n + 1, false));

    while(m--){
        cin >> x >> y;
        AdjMatrix[x][y] = true;
        AdjMatrix[y][x] = true;
    }

    DFS(AdjMatrix, v);
    cout << endl;
    BFS(AdjMatrix, v);

    return 0;
}
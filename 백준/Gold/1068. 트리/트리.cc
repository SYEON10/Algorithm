#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int main() {

    int n, rm;
    cin >> n;

    int tree[n];
    int isLeaf[n];

    for(int i = 0; i < n; i++)
        isLeaf[i] = 0;

    for(int i = 0; i < n; i++){
        cin >> tree[i];
        isLeaf[tree[i]]++;
    }

    cin >> rm;

    isLeaf[tree[rm]]--;

    stack<int> DFS;

    for(int i = 0; i < n; i++){
        if(isLeaf[i] == 0){
            DFS.push(i);

            while(!DFS.empty()){
                int node = DFS.top();
                DFS.pop();

                if(node == rm){
                    isLeaf[i]++;
                    break;
                }

                if(node == -1){
                    break;
                }

                DFS.push(tree[node]);
            }
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++){
        if(isLeaf[i] == 0)
            count++;
    }

    cout << count;

    return 0;
}
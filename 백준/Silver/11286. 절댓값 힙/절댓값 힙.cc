#include <iostream>
#include <queue>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;

    cin >> n;

    priority_queue<int,vector<int>,greater<>> posHeap;
    priority_queue<int> negHeap;

    while(n--){
        cin >> x;
        if(x == 0){
            if(posHeap.empty()){
                if(!negHeap.empty()){
                    cout << negHeap.top() << '\n';
                    negHeap.pop();
                }
                else{
                    cout << 0 << '\n';
                };
                continue;
            }

            if(negHeap.empty()){
                cout << posHeap.top() << '\n';
                posHeap.pop();
                continue;
            }

            if(posHeap.top() >= -negHeap.top()){
                cout << negHeap.top() << '\n';
                negHeap.pop();
            }
            else{
                cout << posHeap.top() << '\n';
                posHeap.pop();
            }
        }
        if(x > 0){
            posHeap.push(x);
        }
        if(x < 0){
            negHeap.push(x);
        }
    }

    return 0;
}
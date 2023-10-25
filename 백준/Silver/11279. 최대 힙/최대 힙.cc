#include <iostream>
#include <queue>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int x;
    cin >> n;

    priority_queue<int> heap;

    while(n--){
        cin >> x;
        if(x == 0){
            if(!heap.empty()){
                cout << heap.top() << '\n';
                heap.pop();
            }
            else cout << 0 << '\n';
        }
        else{
            heap.push(x);
        }
    }


    return 0;
}
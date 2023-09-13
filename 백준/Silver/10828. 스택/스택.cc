#include <iostream>

using namespace std;

class Stack
{
private:
    int arr[10000];
    int topPointer = -1;

public:
    void push(int x){
        arr[++topPointer] = x;
    }

    int pop(){
        if(empty()){
            return -1;
        }
        return arr[topPointer--];
    }

    int size(){
        return topPointer + 1;
    }

    bool empty(){
        if(topPointer == -1)
            return true;
        return false;
    }

    int top(){
        if(empty())
            return -1;
        return arr[topPointer];
    }
};
int main(){

    int n, pushInput;
    string input;
    cin >> n;

    auto *stack = new Stack();

    while(n--) {
        cin >> input;
        if (input == "push") {
            cin >> pushInput;
            (*stack).push(pushInput);
        }
        else if (input == "pop") {
            cout << (*stack).pop() << '\n';
        }
        else if (input == "size") {
            cout << (*stack).size() << '\n';
        }
        else if (input == "empty") {
            if ((*stack).empty())
                cout << 1;
            else cout << 0;
            cout << '\n';
        }
        else if (input == "top") {
            cout << (*stack).top() << '\n';;
        }
    }

    return 0;
}
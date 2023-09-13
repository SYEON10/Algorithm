#include <iostream>

using namespace std;

const int SIZE = 1e4;

class Queue
{
private:
    int arr[SIZE];
    int frontPointer = 0;
    int backPointer = -1;

public:

    void push(int x){
        arr[++backPointer] = x;
    }

    int pop(){
        if(empty())
            return -1;
        return arr[frontPointer++];
    }

    int size(){
        if(empty())
            return 0;
        return backPointer - frontPointer + 1;
    }

    bool empty(){
        return backPointer < frontPointer;
    }

    int front(){
        if(empty())
            return -1;
        return arr[frontPointer];
    }

    int back(){
        if(empty())
            return -1;
        return arr[backPointer];
    }
};

int main(){

    int n, pushInput;
    string input;
    cin >> n;

    auto *queue = new Queue();

    while(n--) {
        cin >> input;
        if (input == "push") {
            cin >> pushInput;
            (*queue).push(pushInput);
        }
        else if (input == "pop") {
            cout << (*queue).pop() << '\n';
        }
        else if (input == "size") {
            cout << (*queue).size() << '\n';
        }
        else if (input == "empty") {
            cout << (*queue).empty() << '\n';
        }
        else if (input == "front") {
            cout << (*queue).front() << '\n';;
        }
        else if (input == "back") {
            cout << (*queue).back() << '\n';;
        }
    }

    return 0;

}
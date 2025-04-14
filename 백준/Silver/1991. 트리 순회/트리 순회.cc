#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
unordered_map<char, vector<char>> tree;

void Preorder(char start){
    if(start == '.') return;
    cout << start;
    Preorder(tree[start][0]);
    Preorder(tree[start][1]);
}

void Inorder(char start){
    if(start == '.') return;
    Inorder(tree[start][0]);
    cout << start;
    Inorder(tree[start][1]);
}

void Postorder(char start){
    if(start == '.') return;
    Postorder(tree[start][0]);
    Postorder(tree[start][1]);
    cout << start;
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++){
        char root, left_child, right_child;
        cin >> root >> left_child >> right_child;
        tree[root] = {left_child, right_child};
    }

    Preorder('A');
    cout << '\n';
    Inorder('A');
    cout << '\n';
    Postorder('A');
    cout << '\n';

    return 0;
}
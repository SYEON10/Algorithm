#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct node{
    int value;
    node* left;
    node* right;
};

void Postorder(node *n){
    if(n == NULL) return;
    Postorder(n->left); 
    Postorder(n->right);
    cout << n->value << '\n';
}

node* MakeTree(node *n, const int& value){
    if(n == NULL){
        n = new node();
        n->value = value;
        n->left = NULL;
        n->right = NULL;
    }
    else if(value > n->value){
        n->right = MakeTree(n->right, value);
    }
    else{
        n->left = MakeTree(n->left, value);
    }

    return n;
}

int main()
{
    int input;

    node* root = NULL;
    while(cin >> input){
        root = MakeTree(root, input);
    }

    Postorder(root);

    return 0;
}
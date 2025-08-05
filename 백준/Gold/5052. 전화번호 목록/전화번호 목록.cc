#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int num = -1;
    bool end = false;
    vector<Node> child;
};

Node tree;

bool Trie(string input) {
    Node* currentNode = &tree;
    for (int i = 0; i < input.size(); i++) {
        int n = input[i] - '0';
        bool find = false;

        int c = 0;
        for (; c < currentNode->child.size(); c++) {
            Node* child = &currentNode->child[c];
            if (child->num == n) {
                find = true;
                if (child->end || i == input.size() - 1) {
                    return false;
                }
                break;
            }
        }

        if (find) {
            currentNode = &currentNode->child[c];
            continue;
        }

        if (i == input.size() - 1) 
            currentNode->child.push_back({ n, true });
        else currentNode->child.push_back({ n, false });
        currentNode = &currentNode->child.back();
    }

    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string input;
        bool ans = true;
        tree = { -1, false };

        while (n--) {
            cin >> input;
            if (!Trie(input)) {
                ans = false;
                continue;
            }
        }

        if (ans) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}
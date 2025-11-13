#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <stack>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    string str;
    cin >> str;

    vector<int> alphabet(26, 0);
    for(char c : str){
        alphabet[c - 'A']++;
    }

    char add;
    bool isAdd = false;

    stack<char> stk;
    vector<char> res;

    for(int i = 0; i < 26; i++){
        char c = 'A' + i;
        if(alphabet[i] & 1){
            if(isAdd){
                cout << "I'm Sorry Hansoo";
                return 0;
            }
            isAdd = true;
            add = c;
        }
        for(int j = 0; j < alphabet[i] / 2; j++){
            res.push_back(c);
            stk.push(c);
        }
    }

    for(char c : res){
        cout << c;
    }

    if(isAdd) cout << add;

    while(!stk.empty()){
        cout << stk.top();
        stk.pop();
    }

    return 0;
}
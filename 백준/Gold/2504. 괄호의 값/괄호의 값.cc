#include <iostream>
#include <stack>
#include <vector>
#include <map>

using namespace std;

const int SIZE = 15;

int main()
{
    string line;
    vector<int> count(SIZE, 0);
    cin >> line;

    stack<int> st;
    map<char, char> m;

    m[']'] = '[';
    m[')'] = '(';

    for(int i = 0; i < line.size(); i++){
        char c = line[i];
        if(c == '(' || c == '['){
            st.push(c);
        }
        if(c == ')' || c == ']'){
            if(st.empty() || st.top() != m[c]){
                cout << 0;
                return 0;
            }

            int depth = st.size();
            int mul;

            if(c == ')'){
                mul = 2;
            }
            if(c == ']'){
                mul = 3;
            }

            if(count[depth + 1] != 0){
                count[depth] += (mul * count[depth + 1]);
                count[depth+1] = 0;
            }
            else count[depth] += mul;

            st.pop();
        }
    }

    cout << count[1];

    return 0;
}
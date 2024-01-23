#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string line;
    int stack = 0;
    int ans = 0;
    char pch;

    cin >> line;

    for(int i = 0; i < line.size(); i++){
        if(line[i] == '('){
            stack++;
            pch = '(';
        }
        else{
            stack--;
            ans += (pch == '(') ? stack : 1;
            pch = ')';
        }
    }

    cout << ans;

    return 0;
}
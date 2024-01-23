#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    string line;
    int count = 0;
    bool laser = true;
    stack<char> temp;

    cin >> line;

    for(int i = 0; i < line.size(); i++){
        char c = line[i];
        if(c == '('){
            laser = true;
            temp.push(c);
        }
        else{
            temp.pop();

            if(laser){
                count += temp.size();
            }
            else{
                count++;
            }

            laser = false;
        }
    }

    cout << count;

    return 0;
}
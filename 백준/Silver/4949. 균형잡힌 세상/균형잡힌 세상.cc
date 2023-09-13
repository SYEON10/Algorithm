#include <iostream>
#include <stack>
#include <map>
#include <vector>

using namespace std;

// 정의 :
// 1. '.' 을 기준으로 문자열을 나눠(split)
// 2. 각 문장의 괄호 균형 여부 조사 > 스택 사용(왼쪽 : Push, 오른쪽 : Pop)

int main(){
    vector<string> lines;
    string str;

    while(true){
        getline(cin, str, '.');
        if(str == "")
            break;
        lines.emplace_back(str);
        cin.ignore(); //버퍼 비워서 \n 날리기
        str == "";
    }

    stack<char> stack;
    bool pass;

    for(string line : lines){
        pass = true;
        //괄호 균형여부 조사
        for(int i = 0; i < line.size();i++){
            if(line[i] == '['){
                stack.push('[');
            }
            else if(line[i] == '('){
                stack.push('(');
            }
            else if(line[i] == ')'){
                if(!stack.empty() && stack.top() == '('){
                    stack.pop();
                }
                else{
                    pass = false;
                    break;
                }
            }
            else if(line[i] == ']'){
                if(!stack.empty() && stack.top() == '['){
                    stack.pop();
                }
                else{
                    pass = false;
                    break;
                }
            }
        }
        
        if(!stack.empty()){
            pass = false;
        }

        if(pass)
            cout << "yes\n";
        else cout << "no\n";

        while(!stack.empty()){
            stack.pop();
        }
    }

}
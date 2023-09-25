#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

//팰린드롬이 만들어질 수 있는 조건
//1. 홀수 개인 문자가 없거나 1개만 있어야 한다.

//위 조건을 만족하는 문자열로 팰린드롬을 만드는 방법
//1. 각 문자열의 수를 파악한다.
//2. 사전순으로 빠른 문자열의 절반을 전부 나열해나간다. 단, 홀수개는 무조건 마지막에 온다.
//3. 나머지 절반의 문자열을 뒤집어 그 뒤에 붙인다.

//key-value 로 key에 알파벳 저장하고 그 개수를 value에 저장한다.

int main(){

    map<char, int> dict;
    char c, odd = '\0';
    string answer, submit;

    while(cin >> c){
        if(c == '!')
            break;
        dict[c]++;
    }

    for(auto in : dict){
        if(in.second % 2 != 0 && odd != '\0'){
            cout << "I'm Sorry Hansoo";
            return 0;
        }
        if(in.second % 2 != 0){ //홀수면
            odd = in.first;
        }
        for(int i = 0; i < in.second / 2; i++){
            answer += in.first;
        }
    }

    submit += answer;
    if(odd != '\0')
        submit += odd;
    reverse(answer.begin(), answer.end());
    submit += answer;

    cout << submit;

    return 0;
}
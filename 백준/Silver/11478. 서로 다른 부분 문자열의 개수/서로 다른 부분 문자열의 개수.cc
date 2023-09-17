#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main(){

    string input, str;
    cin >> input;

    unordered_set<string> strSet;

    for(int i = 1; i <= input.size(); i++){ //문자 수 ++
        for(int j = 0 ; j < input.size() - i + 1; j++){ //포인터
            for(int k = j; k < j + i; k++){ //끊기
                str += input[k];
            }
            strSet.insert(str);
            str = "";
        }
    }

    cout << strSet.size();

    return 0;
}
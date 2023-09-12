#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string& a, string& b){
    if(a.length() != b.length()){ //1. 길이 비교
        return a.length() < b.length();
    }
    else{

        //2. 자릿수 숫자 더하기
        int intA = 0;
        int intB = 0;

        for(int i = 0; i < a.length(); i++){
            if(std::isdigit(a[i]))
                intA += int(a[i]) - 48;
        }

        for(int i = 0; i < b.length(); i++){
            if(std::isdigit(b[i]))
                intB += int(b[i]) - 48;
        }

        //3. 자릿수 숫자가 같으면 사전순 비교, 다르면 자릿수 숫자로 비교
        if(intA == intB){
            return a < b;
        }
        else{
            return intA < intB;
        }
    }
}

int main(){

    int n;
    cin >> n;

    vector<string> serial(n, "");

    //입력
    for(int i = 0; i < n; i++){
        cin >> serial[i];
    }

    sort(serial.begin(), serial.end(), compare);

    //출력
    for(int i = 0; i < n; i++){
        cout << serial[i] << '\n';
    }

    return 0;
}
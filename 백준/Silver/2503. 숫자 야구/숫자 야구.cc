#include <iostream>
#include <vector>

using namespace std;

vector<bool> number(1000, true);

struct Input{
    string num;
    int strike = 0;
    int ball = 0;
};

void NumberChecker(const Input &input){

    int temp;

    int cmp[3];
    for(int i = 0; i < 3; i++)
        cmp[i] = input.num[i] - '0';

    for(int i = 123; i < 1000; i++){
        if(number[i]){

            //Check
            temp = i;

            int num[3];
            int strike = 0;
            int ball = 0;

            for(int j = 0; j < 3; j++){
                num[2 - j] = temp % 10;
                temp /= 10;
            }

            if(num[0] == num[1] || num[1] == num[2] || num[0] == num[2] || num[0] == 0 || num[1] == 0 || num[2] == 0){
                number[i] = false;
                continue;
            }

            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    if(cmp[k] == num[j]){
                        if(k == j) strike++;
                        else ball++;
                    }
                }
            }

            if(!(input.strike == strike && input.ball == ball))
                number[i] = false;
        }
    }
}

int main(){

    //입력
    int n, count = 0;
    cin >> n;

    while(n--){
        Input input;
        cin >> input.num >> input.strike >> input.ball;
        NumberChecker(input);
    }

    //출력

    for(int i = 123; i < 1000; i++){
        if(number[i])
            count++;
    }

    cout << count;

    return 0;
}
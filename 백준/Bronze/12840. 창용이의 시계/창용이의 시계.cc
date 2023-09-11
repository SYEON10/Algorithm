#include <iostream>

using namespace std;

//정의 : 60 기준으로 단위가 업데이트 됨
//3개의 입력 처리
//1. 현재 시간을 초단위로 저장
//2. 앞으로는 더하고, 뒤로는 빼기(0 혹은 23시 59분 59초 케이스 생각)
//3. 출력 시 시, 분, 초 단위로 출력하기

int CalculateTime(int time){
    time %= 24 * 60 * 60;
    if(time < 0){
        time += 24 * 60 * 60;
    }

    return time;
}

void PrintTime(int time){
    int hour;
    int min;
    int sec;

    hour = time / (60 * 60);
    time %= 60 * 60;
    min = time / 60;
    sec = time % 60;

    cout << hour << " " << min << " " << sec << '\n';
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int hour, min, sec;
    int n;
    int presentTime, query, input;

    cin >> hour >> min >> sec;
    cin >> n;

    presentTime = hour * 60 * 60 + min * 60 + sec;

    while(n--){
        cin >> query;
        switch(query){
            case 1:
                cin >> input;
                presentTime = CalculateTime(presentTime + input);
                break;
            case 2:
                cin >> input;
                presentTime = CalculateTime(presentTime - input);
                break;
            case 3:
                PrintTime(presentTime);
                break;
            default: cout << "ERROR! >> Wrong Input";
        }
    }

    return 0;
}
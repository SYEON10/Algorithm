#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    long long hurt, count;
    long long result = 0;
    cin >> hurt >> count;


    if(hurt == 1 || hurt == 5){
        result += (hurt - 1) + (count * 8);
    }
    else{
        //1번, 5번이 아닐 경우
        result += count * 4;

        if(count %2 == 0){ //짝수 -> 1번 손가락에서부터 세기 시작
            result += hurt - 1;
        }
        else{ //홀수 > 5번 손가락에서부터 세기 시작
            result += 5 - hurt;
        }
    }

    cout << result;

    return 0;
}
#include <iostream>

using namespace std;

//정의 : 일정 구간 내의 카드 순서 뒤집기

int main(){

    const int arrSize = 20;
    int querySize = 10;
    int arr[arrSize];
    int start, end;

    //20까지 순서대로 숫자 채우기
    for(int i = 1; i <= 20; i++){
        arr[i - 1] = i;
    }

    while(querySize--){
        cin >> start >> end;

        //카드 순서 뒤집기
        for(int i = 0; i < ((end - start) / 2) + 1; i++){
            swap(arr[start + i - 1], arr[end - i - 1]);
        }
    }

    //출력
    for(int i = 0; i < arrSize; i++){
        cout << arr[i] << ' ';
    }

    return 0;
}
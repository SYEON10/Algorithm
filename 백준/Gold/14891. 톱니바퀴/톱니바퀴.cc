#include <iostream>
#include <vector>

using namespace std;

const int NUMBER = 4;
const int SIZE = 8;

int CalculatePTR(int ptr, int num){
    if(ptr >= 0)
        ptr = (ptr + num) % SIZE;
    if(ptr < 0){
        ptr = SIZE + ptr;
    }

    return ptr;
}

void Rotate(int &out_ptr, int rotation){
    if(rotation == 1){
        out_ptr = CalculatePTR(out_ptr, -1);
    }
    if(rotation == -1){
        out_ptr = CalculatePTR(out_ptr, 1);
    }
}

void RotateWheels(const vector<vector<int>> &wheelList, int ptr[], int num, int rotation){
    bool doRotate[NUMBER] = {false};
    doRotate[num] = true;

    for(int i = num - 1; i >= 0; i--){
        if(wheelList[i][CalculatePTR(ptr[i],2)] != wheelList[i + 1][CalculatePTR(ptr[i + 1],-2)]){
            doRotate[i] = true;
        }
        else break;
    }

    for(int i = num + 1; i < NUMBER; i++){
        if(wheelList[i - 1][CalculatePTR(ptr[i - 1],2)] != wheelList[i][CalculatePTR(ptr[i],-2)]){
            doRotate[i] = true;
        }
        else break;
    }

    for(int i = 0; i < 4; i++){
        if(doRotate[i]){
            if((num - i) % 2 == 0)
                Rotate(ptr[i], rotation);
            else Rotate(ptr[i], -rotation);
        }
    }
}

int main(){

    int n, num, rotation, add = 0;
    int ptr[NUMBER] = {0}; //12시 방향의 값을 가리키는 포인터
    vector<vector<int>> wheelList(NUMBER);

    vector<int> wheel(SIZE);
    string temp;

    for(int i = 0; i < NUMBER; i++){
        cin >> temp;

        for(int j = 0; j < SIZE; j++){
            wheel[j] = temp[j] - '0';
        }
        wheelList[i] = wheel;
    }

    cin >> n;
    while(n--){
        cin >> num >> rotation;
        RotateWheels(wheelList, ptr, num - 1, rotation);
    }

    int mul = 1;
    for(int i = 0; i < NUMBER; i++){
        if(wheelList[i][ptr[i]] == 1){
            add += mul;
        }
        mul *= 2;
    }

    cout << add;

    return 0;
}
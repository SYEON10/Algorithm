#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

void TimeInsert(int& time){
    int tempInt;
    char tempChar;

    cin >> tempInt >> tempChar;
    time = tempInt * 100;
    cin >> tempInt;
    time += tempInt;
}

int main(){

    int start, end, streamingEnd, time, tempInt;
    int count = 0;
    string name;
    char tempChar;
    map<string, bool> attendances; //<닉네임, 참석여부>
    //목적 똑바로 생각할 것. 닉네임과 시간이 중요한 게 아니라 참석여부가 목적임.

    TimeInsert(start);
    TimeInsert(end);
    TimeInsert(streamingEnd);

    while(cin >> tempInt >> tempChar >> time){
        cin >> name;
        time += tempInt * 100;

        if(time <= start){
            attendances[name] = true;
        }
        else if(time >= end && time <= streamingEnd){
            if(attendances[name]){
                count++;
                attendances[name] = false;
            }
        }
    }

    cout << count;

    return 0;
}
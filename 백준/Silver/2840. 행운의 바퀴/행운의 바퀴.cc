#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int wheelSize, ratateNum, rotate, wheelPtr = 0;
    char letter;
    cin >> wheelSize >> ratateNum;

    vector<char> wheel(wheelSize, '?');

    for(int count = 0; count < ratateNum; count++){
        cin >> rotate >> letter;
        wheelPtr = (wheelPtr + rotate) % wheelSize;
        if(wheel[wheelPtr] == '?' || wheel[wheelPtr] == letter){
            wheel[wheelPtr] = letter;
            for(int idx = wheelPtr - 1; idx >= 0; idx--){
                if(wheel[idx] == letter){
                    cout << '!';
                    return 0;
                }
            }
            for(int idx = wheelSize - 1; idx > wheelPtr; idx--){
                if(wheel[idx] == letter){
                    cout << '!';
                    return 0;
                }
            }
        }
        else {
            cout << '!';
            return 0;

        }
    }

    for(int idx = wheelPtr; idx >= 0; idx--){
        cout << wheel[idx];
    }
    for(int idx = wheelSize - 1; idx > wheelPtr; idx--){
        cout << wheel[idx];
    }

    return 0;
}
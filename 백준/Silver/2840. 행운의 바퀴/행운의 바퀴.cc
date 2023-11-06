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
    vector<bool> isAvailable(26, false);

    for(int count = 0; count < ratateNum; count++){
        cin >> rotate >> letter;
        wheelPtr = (wheelPtr + rotate) % wheelSize;
        if(wheel[wheelPtr] == letter){
            continue;
        }
        if(wheel[wheelPtr] != '?' || isAvailable[letter - 'A']){
            cout << '!';
            return 0;
        }
        wheel[wheelPtr] = letter;
        isAvailable[letter - 'A'] = true;
    }

    for(int idx = wheelPtr; idx >= 0; idx--){
        cout << wheel[idx];
    }
    for(int idx = wheelSize - 1; idx > wheelPtr; idx--){
        cout << wheel[idx];
    }

    return 0;
}
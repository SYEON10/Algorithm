#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count, n, temp;
    cin >> count;

    while(count--){
        cin >> n;
        unordered_set<int> note1;
        vector<int> note2;

        //입력
        while(n--){
            cin >> temp;
            note1.insert(temp);
        }

        cin >> n;
        note2.assign(n, 0);

        //입력 및 연산
        for(int i = 0; i < n; i++){
            cin >> note2[i];
            auto it = note1.find(note2[i]);
            if(it == note1.end()) //수첩1에 없으면
                cout << 0<< '\n';
            else{
                cout <<  1<< '\n';
            }
        }
    }

    return 0;
}